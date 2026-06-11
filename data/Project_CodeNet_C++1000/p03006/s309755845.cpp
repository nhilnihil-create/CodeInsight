#include <bits/stdc++.h>
#define cout16 cout << setprecision(16) 
#define rep(i,n) for(int i=0;i<n;i++ )
#define rep2(i,f,n) for(int i=f;i<n;i++ )
#define SORT(A) sort(A.begin(),A.end())
#define REV(A) reverse(A.begin(),A.end())
typedef long long int ll;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vll = std::vector<ll>;
using vvll = std::vector<std::vector<ll>>;
using P = std::pair<int,int>;
using vp = std::vector<P>;
using namespace std;
#define INF 1001001001
#define LL_INF 1001001001001001001
#define fi first
#define se second

//Union-Find Tree
class UnionFindTrees{
	public:
		//　_n : ノード数
		UnionFindTrees(int _n){
			n = _n;
			root = vector<int>(_n);
			tree_size = vector<int>(_n,1);
			rep(i,_n) root[i] = i;
		}
		//　xの根っこ（属する木）を見つける
		int find(int x){
			if(root[x]==x) return x;
			else return root[x]=find(root[x]);			
		}
		//　xとyの属する木が同じかどうか判定する
		bool same(int x, int y){
			return find(x)==find(y);
		}
		//　xとyの属する木を統合する
		void merge(int x, int y){
			if(same(x,y)) return;
			x = find(x);
			y = find(y);
			if(tree_size[x]<tree_size[y]) swap(x,y);			
			root[y] = x;
			tree_size[x] += tree_size[y];
			n--;			
		}
		//　xが属する木のサイズを出力する
		int get_tree_size(int x){
			return tree_size[find(x)];
		}
		//　木の数を出力する
		int get_forest_size(){return n;}
	private:
		vector<int> root;
		vector<int> tree_size;
		int n;
};

int main(void) {
	int n; cin >> n;
	vi x(n),y(n);
	rep(i,n) cin >> x[i] >> y[i];
	int ans = INF;
	rep(i,n)rep2(j,i+1,n){
		int p,q;
		p = x[i]-x[j];
		q = y[i]-y[j];
		UnionFindTrees uft(n);
		rep(ni,n)rep2(nj,ni+1,n){
			int dx,dy;
			dx = x[ni]-x[nj];
			dy = y[ni]-y[nj];
			if( (p==dx&&q==dy) || (-p==dx&&-q==dy) )
				uft.merge(ni,nj);
		}
		ans = min(ans,uft.get_forest_size());
	}
	if(n==1) ans = 1;
	cout << ans << endl;
}


