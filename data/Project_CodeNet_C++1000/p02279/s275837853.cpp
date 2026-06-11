#include<bits/stdc++.h>
using namespace std;
typedef vector<int>V;
void func(int node,int par,int rang);
bool flg[100000]={0};
int n,u,k,c;
V v[100000];
struct Node{
	int parent,depth;
};
Node T[100000];
int main(void){
	
	int i,j;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>u>>k;
		T[i].parent=0;
		T[i].depth=0;
		for(j=0;j<k;j++){
			cin>>c;
			flg[c]=1;
			v[u].push_back(c);
		}
	}
	for(i=0;i<n;i++){
		if(!flg[i]){
			func(i,-1,0);
		}
	}
	//cout<<"check2"<<endl;
	for(i=0;i<n;i++){
		cout<<"node "<<i<<": parent = "<<T[i].parent<<", depth = "<<T[i].depth<<", ";
		if(v[i].empty()){
			if(T[i].parent==-1){
				cout<<"root, []"<<endl;
			}
			else{
				cout<<"leaf, []"<<endl;
			}
		}
		else{
			if(T[i].parent==-1){
				cout<<"root, ["<<v[i][0];
				for(j=1;j<v[i].size();j++){
					cout<<", "<<v[i][j];
				}
				cout<<"]"<<endl;
			}
			else{
				cout<<"internal node, ["<<v[i][0];
				for(j=1;j<v[i].size();j++){
					cout<<", "<<v[i][j];
				}
				cout<<"]"<<endl;
			}
		}
	}
	return 0;
}
void func(int node,int par,int rang){
	int i;
	//cout<<"check"<<endl;
	T[node].parent=par;
	T[node].depth=rang;
	//cout<<"cheack1"<<endl;
	for(i=0;i<v[node].size();i++){
		func(v[node][i],node,rang+1);
	}
}
	
	
	
	
	
