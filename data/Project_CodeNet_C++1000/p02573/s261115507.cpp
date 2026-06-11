#include <bits/stdc++.h>
	
using namespace std;
inline void FAST_IO(){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

template<class F, class S> ostream& operator<<(ostream& os, pair<F, S> &p) {
	os << "(" << p.first << "," << p.second << ")";
	return os;
}

template<class T, class S> ostream& operator<<(ostream& os, map<T, S> &v) {
	os << "{";
	for(auto &i : v) cout << "{" << i.first << "," << i.second << "}";
	os << "}";
	return os;
}

template<class T> ostream& operator<<(ostream& os, set<T> &v) {
	os << "{";
	for(auto &i : v) cout << i << ",";
	os << "}";
	return os;
}
 
template<class T> ostream& operator<<(ostream& os, vector<T> &v) {
	os << "[";
	if(v.size()) os << v[0];
	for(int i = 1; i < v.size(); ++i) os << "," << v[i];
	os << "]";
	return os;
}

/*----------------------------------------------------------------------------*/

class UF{
public:
	int *a, *sz;
	int n;

	UF(int n){
		sz = new int[n];
		a = new int[n];
		this->n = n;
		
		for(int i =0 ; i < n; i++)
			a[i] = i, sz[i] = 1;
	}
	
	~UF(){
		delete sz;
		delete a;
	}
	
	int root(int p){
		while(a[p] != p) {
			a[p] = a[a[p]];
			p = a[p];
		}
		return p;
	}
	
	void merge(int p, int q){
		int i = root(p);
		int j = root(q);
		
		if(i == j) return;
		
		if(sz[i] > sz[j]) a[j] = i, sz[i] += sz[j];
		else a[i] = j, sz[j] += sz[i];
	}
	
	bool find(int p, int q){
		return root(p) == root(q);
	}	
};

int main (){
	// FAST_IO();

	int n,m;
	cin >> n >> m;
	UF uf(n+1);

	int resp = 1;
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (!uf.find(a,b)) {
			uf.merge(a,b);
			resp = max(resp, uf.sz[uf.root(a)]);
		}
	}

	cout << resp << endl;

	return 0;
}
