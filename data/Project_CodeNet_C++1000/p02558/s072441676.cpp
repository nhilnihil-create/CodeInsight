#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cctype>
#include<map>
#include<cstring>
#include<bitset>
#include<cassert>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,b) for (int (i)=a;(i)<(b);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long int;

const int inf = 1001001000;
const long long int Inf = 1001001001001001000;



void print(vector<vector<int>> a){
	for (int i = 0; i < a.size(); i++)
	{
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<vector<long long int>> a){
	for (int i=0;i<a.size();i++){
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(vector<long long int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(set<int> a){
	for (auto x:a)
		cout << x << " ";
	cout << endl;
}

//UnionFind木のテンプレ.parentには根のindexが入っている.
//根には連結成分のサイズが入っている.nはノード数.
class UnionFind{
public:
	vector<int> parent;
	UnionFind(){}
	UnionFind(int n){
		this->parent = vector<int>(n,-1);
	}
	int root(int x){
		if (this->parent[x] < 0) return x;
		this->parent[x] = root(this->parent[x]);
		return this->parent[x];
	}
	int unite(int x, int y){
		int rx = this->root(x);
		int ry = this->root(y);
		if (rx == ry) return false;
		if (this->parent[rx] > this->parent[ry]) swap(rx, ry);
		this->parent[rx] += this->parent[ry];
		this->parent[ry] = rx;
		return true;
	}
	int same(int x, int y){
		int rx = this->root(x);
		int ry = this->root(y);
		return rx == ry;
	}
	int size(int x){
		return -this->parent[this->root(x)];
	}
};

int main()
{
	int n, q;
	cin >> n >> q;
	UnionFind uf(n);
	rep(i,q){
		int t, u, v;
		cin >> t >> u >> v;
		if(t == 0){
			uf.unite(u, v);
		} else {
			cout << uf.same(u, v) << endl;
		}
	}

	return 0;
}


