#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef int Weight;
struct Edge{
	int src,dst;
	Weight weight;
};

bool asc(const Edge &e,const Edge &f){
	return e.weight < f.weight;
}

vector<Edge> Edges;
vector<int> L(100005,-1);

int check(Edge &e,int n){
	int j;
	if (L[e.src]!=L[e.dst]){
		int t = L[e.dst];
		for (j=0;j<n;j++){
			if (L[j]==t){
				L[j]=L[e.src];
			}
		}
		return 1;
	}else{
		return 0;
	}
}

int main(){
	int n,m,i,j,w;
	cin >> n ;
	
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin >> w;
			if ((w!=-1)&&(i>j)){
				Edge edge={i,j,w};
				Edges.push_back(edge);
			}
		}
	}
	
	sort(Edges.begin(),Edges.end(),asc);
	
	m = Edges.size();
	
	for (j=0;j<n;j++){
		L[j]=j;
	}
	
	int TotalWeight=0;
	int count=0;
	int k;
	for (i=0;i<m;i++){
		if (count==n-1){break;}
		if (check(Edges[i],n)){
			TotalWeight+=Edges[i].weight;
			count++;
		}
	}
	cout << TotalWeight<<endl;
	return 0;
}