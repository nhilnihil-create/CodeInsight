#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
 
#define ll long long
 
#define pq(name,type) priority_queue<type> name
#define vec(name,type,length,value) vector<type> name(length,value)
#define vec2(name,type,length,width,value) vector<vector<type>> name(length,vector<type>(width,value));
 
int main(){
	struct UnionFind{
	vector<int> par; //親の番号

	UnionFind(int N) : par(N){ //初期化で最初はすべてが根であるとする
		for(int i = 0;i < N;i++) par[i] = i;
	}

	int root(int x){ //データxが属する木の根を再帰的に求める
		if(par[x] == x) return x; //根を返す
		return par[x] = root(par[x]); //データxの親の番号でroot()を再帰する
	}

	void unite(int x,int y){ //xとyの木を併合
		int rx = root(x); //xの根
		int ry = root(y); //yの根
		if(rx == ry) return; //同じ木にある時はそのまま
		par[rx] = ry; //別々の木にある時は根を同じにしてくっつける
	}
	
	bool same(int x,int y){ //xとyが同じ木に属するか判別する
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}
};
  
  int N,M;
  cin >> N >> M;
  UnionFind u(N);
  froop1(0,M){
   int a,b;
    cin >> a >> b;
    a--;b--;
    u.unite(a,b);
  }
	int count = 0;
  set<int> m;
  froop1(0,N){
    int p = u.root(i);
        m.insert(p);
  }
  count = m.size() - 1;
  
    cout << count << endl;
}