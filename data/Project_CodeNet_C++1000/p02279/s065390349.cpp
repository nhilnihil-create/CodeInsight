#include<iostream>
#include<vector>
using namespace std;

struct Vertex{
		int parent;
		int depth;
	};

void treeMake(int vertex,int depth,vector< vector<int> > &T, vector<Vertex> &V){
	if(depth==0){
		V[vertex].parent=-1;
	}
	V[vertex].depth=depth;
	if(T[vertex].size()==0){
		return;
	}
	int i;
	for(i=0;i<T[vertex].size();i++){
		V[T[vertex][i]].parent=vertex;
		treeMake(T[vertex][i],depth+1,T,V);
	}
}

int main(){
	int n,i,j,k,d,e;
	cin >> n;
	
	vector< vector<int> > T(n);
	vector<int> check(n,0); 
	
	for (i=0;i<n;i++){
		cin >> k >> d;
		for (j=0;j<d;j++){
			cin >> e;
			T[k].push_back(e);
			check[e]=1;
		}
	}
	
	int r;
	for (i=0;i<n;i++){
		if(check[i]==0){
			r=i;
			break;
		}
	}
	
	vector<Vertex> V(n);
	
	treeMake(r,0,T,V);
	
	for (i=0;i<n;i++){
		cout << "node "<<i<<": parent = "<< V[i].parent <<", depth = "<<V[i].depth<<", ";
		if(V[i].parent==-1){
			cout << "root, ";
		}else if(T[i].size()==0){
			cout << "leaf, ";
		}else{
			cout << "internal node, ";
		}
		
		cout << "[";
		for (j=0;j<T[i].size();j++){
			if(j==T[i].size()-1){
				cout << T[i][j] ;
			}else{
				cout << T[i][j] << ", ";
			}
		}
		cout << "]"<<endl;
	}
}