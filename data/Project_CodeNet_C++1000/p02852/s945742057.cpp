//includes
#include<iostream>
#include<vector>
#include<set>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<map>
#include<queue>
#include<iomanip>
#include<numeric>
#include<assert.h>
#include<cstring>
#include<unordered_map>
#include<bitset>

//macros and consts
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define FORE(i,a) for(auto &i : a)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define accm accumulate
#define Fi first
#define Se second
#define INF 1e9
#define llINF (1LL<<60)
#define mINF -1e9
#define mllINF -(1LL<<60)
#define endl "\n"
#define CONT continue
#define BRK break
#define modulo(n, m) (((n)%(m)+(m))%m)

//shorter types
using namespace std;
using ll = long long;
using vi = std::vector<int>;
using vc = std::vector<char>;
using vll = std::vector<long long>;
using vs = std::vector<string>;
using Mi = map<int,int>;
using Mll = map<ll,ll>;
using UMi = unordered_map<int,int>;
using UMll = unordered_map<ll,ll>;
using Pi = pair<int,int>;
using Pll = pair<ll,ll>;
using vPi = vector<Pi>;
using vPll = vector<Pll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvc = vector<vector<char>>;
using vvs = vector<vector<string>>;
using pqgi = priority_queue<int,vector<int>,greater<int>>;
using pqsi = priority_queue<int,vector<int>,less<int>>;
using pqgll = priority_queue<int,vector<int>,greater<int>>;
using pssll = priority_queue<int,vector<int>,less<int>>;
template<class T>
using vec = vector<T>;
#define int long long




int N,M;
string S;
template<int NV>
struct LazySegmentTree{
	const int ldef = llINF;
	const int def = llINF;
	vector<int> node,lazy;
	LazySegmentTree(){
		node.resize(NV * 2,def);
		lazy.resize(NV * 2, ldef);
	}
	int comp(int l, int r){
		return min(l,r);
	}
	int get(int a, int b, int k, int l, int r){
		push(k,l,r);
		if(r <= a || b <= l){
			return def;
		}
		if(a <= l && r <= b){
			return node[k];
		}
		auto x = get(a,b,k * 2 + 1, l, (l + r) / 2);
		auto y = get(a,b,k * 2 + 2, (l + r) / 2, r);
		return comp(x,y);
	}
	int get(int a, int b){
		return get(a,b,0,0,NV);
	}
	void update(int a, int b, int v, int k, int l, int r){
		push(k,l,r);
		if(r <= a || b <= l){
			return;
		}
		if(a <= l && r <= b){
			setLazy(k,v);
			push(k,l,r);
		}
		else{
			update(a,b,v,k * 2 + 1, l, (l + r) / 2);
			update(a,b,v,k * 2 + 2, (l + r) / 2, r);
			node[k] = comp(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	void update(int a, int b, int v){
		update(a,b,v,0,0,NV);
	}
	void setLazy(int i, int v){
		lazy[i] = min(lazy[i], v);
	}
	void push(int k, int l, int r){
		if(lazy[k] != ldef){
			node[k] = min(node[k],lazy[k]);
			if(r - l > 1){
				setLazy(k * 2 + 1, lazy[k]);
				setLazy(k * 2 + 2, lazy[k]);
			}
		}
		lazy[k] = ldef;
	}
};
//here begins your code
LazySegmentTree<1 << 17> lst;
vector<int> idx[101010];
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> N >> M;
  cin >> S;
  lst.update(N, N+1, 0);
  for(int i = N; i>=0; i--){
  	if(S[i] == '0'){
  		int mi = lst.get(i,i+1);
  		int l = max(0LL,i-M);
  		lst.update(l,i,mi+1);
  	}
  }

  if(lst.get(0,1) == llINF){
  	cout << -1 << endl;
  	return 0;
  }


  for(int i = 0 ; i < N + 1; i++){
  	if(S[i] == '0'){
  		idx[lst.get(i,i+1)].push_back(i);
  	}
  }


  vector<int> ans;
  int cu = 0;
  int dp = lst.get(0,1);
  while(cu < N){
  	int nxt = *upper_bound(idx[dp - 1].begin(),idx[dp - 1].end(), cu);
  	ans.push_back(nxt - cu);
  	cu = nxt;
  	dp--;
  }

  int n = ans.size();
  for(int i = 0; i < n; i++){
  	if(i) printf(" ");
  	printf("%lld",ans[i]);
  }
  printf("\n");
  //check types
  //do not eb if you resize
  //resize before you access by idx
  return 0;
} 