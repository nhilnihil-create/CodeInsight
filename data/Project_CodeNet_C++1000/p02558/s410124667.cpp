#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <limits>
#include <numeric>

#define el '\n'
typedef long long ll;

using namespace std;



class DSU{
	public:
	 vector<int> siz, par;


	 DSU(int n){
	 	this -> siz.resize(n, 1);
	 	this -> par.resize(n);
	 	for (int i = 0; i < n; i++){
	 		this -> par[i] = i;
	 	}
	 }


	 void _union(int a, int b){
	 	int pa = this -> _get(a),
	 		pb = this -> _get(b);
 		if (pa == pb) return ;
 		if (this -> siz[pa] > this -> siz[pb]){
 			this ->  siz[pa] += this ->  siz[pb];
 			par[pb] = pa;
 		} else {
 			this ->  siz[pb] += this -> siz[pa];
 			par[pa] = pb;
 		}

	 }

	 int _get(int ell){
	 
	 	return this -> par[ell] = (this -> par[ell] == ell ? ell : this -> _get(this -> par[ell])); 
	 }


	 bool _chech(int a, int b){
	 	return this -> _get(a) == this -> _get(b);
	 }
};


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >>n>>m;
	bool a;
	int u,v;
	DSU *ds = new DSU(n);
	for(int i = 0; i < m; i++){
		cin >>a>>u>>v;
		if (!a){
			ds -> _union(u,v);
		} else {
			if (ds -> _chech(u,v)) {
				cout << 1 << el;
			} else {
				cout << 0 << el;
			}
		}
	}
}