#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#include<queue>
#include<cstdio>
#define rep(i,n) for (int i=0;i<(n);++i)
using ll = long long;
using namespace std;
using P = pair<int,int>;

struct UnionFind{
    vector<int> r;

    UnionFind(int N){
        r = vector<int>(N,-1);
    }
    
    int root(int x) {
		if (r[x] < 0) return x;
		return r[x] = root(r[x]);
	}
 
	bool unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (r[x] > r[y]) swap(x, y);
		r[x] += r[y];
		r[y] = x;
		return true;
	}
 
	int size(int x) {
		return -r[root(x)];
	}
};
 
 
int main() {
	int N, M;
	cin >> N >> M;
	
	//友達集合を作る
	UnionFind UF(N);//初期化
	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		A -= 1; B -= 1;//0インデックスにする
		UF.unite(A, B);
	}
 
	//最大の友達集合を求める
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans = max(ans, UF.size(i));
	}
 
	cout << ans << endl;
    return 0;
}