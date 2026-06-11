

// void merge(int fromP,int toP)
// {
// 	fromP = find_set(fromP);
// 	toP = find_set(toP);

// 	//UNION by RANK
// 	if(nodes[fromP].rank > nodes[toP].rank)	//fromP has higher rank
// 		nodes[toP].parent = fromP;
// 	else if(nodes[fromP].rank < nodes[toP].rank)	//toP has higher rank
// 		nodes[fromP].parent = toP;
// 	else
// 	{
// 		//Both have same rank and so anyone can be made as parent
// 		nodes[fromP].parent = toP;
// 		nodes[toP].rank +=1;		//Increase rank of parent
// 	}
// }

// void merge_set(int a, int b){
//     a = find_set(a);
//     b = find_set(b);
//     if(a!=b){
//         if(nodes[a].rank<nodes[b].rank){
//             nodes[a].parent = b;
//         }
//         else if(nodes[a].rank<nodes[b].rank){
//             nodes[b].parent = a;
            
//         }
//         else{
//             nodes[b].parent = a;
//             nodes[a].rank+=1;
//         }
//     }
// }

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct node{
    int parent = -1;
    int rank = 0;
};

vector<node> nodes;

void make_set(int x){
    nodes[x].parent = x;
    nodes[x].rank = 1;
}

int find_set(int v)
{
	if(nodes[v].parent==v)
		return v;
	return nodes[v].parent=find_set(nodes[v].parent);
}


void merge_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(nodes[a].rank<nodes[b].rank)swap(a,b);
        nodes[b].parent = a;
        if(nodes[a].rank==nodes[b].rank)nodes[a].rank+=1;
    }
}

int main() {
    
    int N,M,a,b;
    cin>>N>>M;
    nodes.resize(N+1);
    
    for(int i=1;i<=N;++i){
        make_set(i);
    }
    
    for(int i=0;i<M;++i){
        cin>>a>>b;
        merge_set(a,b);
    }
    
    unordered_map<int,int> uomap;
    
    for(int i=1;i<=N;++i){
        ++uomap[find_set(nodes[i].parent)];
    }
    
    cout<<uomap.size()-1;
    
  	return 0;
}

