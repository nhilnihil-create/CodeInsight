#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int n,par[100000],typ[100000],dep[100000];//root,internal node,leaf;
vector <int> chi[100000];

int depth(int now){
	if(dep[now] != -1)return dep[now];
	if(par[now]==-1)return 0;
	return depth(par[now])+1;
}
 
 
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		par[i] = -1;
		dep[i] = -1;
	}

	for(int i=0; i<n; i++){
		int id,k;
		cin >> id >> k;
		if(k == 0) typ[id] = 3;//leaf
		else{
			typ[id] = 2;//IN
			for(int j=0; j<k; j++){
			int c;
			cin >> c;
			chi[id].push_back(c);
			par[c] = id;
			}
		}
	}
	


	for(int i=0; i<n; i++){
		if(par[i] == -1) typ[i] = 1;//root
		cout << "node " << i << ": parent = " << par[i] << ", depth = " << depth(i) <<  ", ";
		if(typ[i] == 1)cout  << "root, [";
		else if(typ[i] == 2)cout  << "internal node, [";
		else cout  << "leaf, [";
		for(int k=0; k < chi[i].size(); k++){
			cout << chi[i][k];
			if(k != chi[i].size()-1) cout  << ", ";
		}
		cout << "]" << endl;
	}

    return 0;
}

