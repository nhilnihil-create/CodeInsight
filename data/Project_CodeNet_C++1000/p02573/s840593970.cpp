#include<bits/stdc++.h>
using ll = long long;
using namespace std;

struct UnionFind {
    vector<int> par;

    UnionFind(int N) : par(N) {
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;cin >> n;
	int m;cin >> m;
	UnionFind uni(n+1);
	for(int i = 0; i < m; i++){
		int a;cin >> a;
		int b;cin >> b;
		uni.unite(a,b);
	}

	vector<int> count = vector<int>(n+1,0);
	int maxCount = 0;
	for(int i = 1; i <= n; i++){
		int tmp = uni.root(i);
		count[tmp]++;
		if(count[tmp]>maxCount){
			maxCount = count[tmp];
		}
	}

	cout << maxCount << endl;

	return 0;
}
