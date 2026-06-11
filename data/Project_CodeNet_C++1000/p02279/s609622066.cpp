#include <iostream>
#include <vector>
using namespace std;

struct node {
	int parent;
	int depth;
	vector<int> children;
	string type;
	node(){
		parent = -1;
		depth = 0;
	}
};

node nodes[100001];

int deep(int i){
	if(nodes[i].parent == -1){
		return 0;
	}
	return deep(nodes[i].parent) + 1;	
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int id,k;
		cin>>id;
		cin>>k;
		for(int j=0;j<k;j++){
			//????????\??????????????\???
			int num;
			cin>>num;
			nodes[num].parent=id;
			nodes[id].children.push_back(num);
		}
	}
	
	for(int i=0;i<n;i++){
		nodes[i].depth = deep(i);
	}
	
	for(int i=0;i<n;i++){
		cout<<"node "<<i<<": ";
		cout<<"parent = "<<nodes[i].parent;
		cout<<", depth = "<<nodes[i].depth;
		
		string type;
		if(nodes[i].children.empty() && nodes[i].parent != -1){
			type ="leaf";
		}else if(nodes[i].parent == -1){
			type = "root";
		}else{
			type = "internal node";
		}
		cout<<", "<<type;
		
		cout<<", [";
		for(int k=0;k<nodes[i].children.size();k++){
			if(k>0){cout<<", ";}
			cout<<nodes[i].children[k];
		}
		cout<<"]"<<endl;
	}
	return 0;
}