#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = ll(A); I < ll(B); ++I)
#define FORR(I,A,B) for(ll I = ll((B)-1); I >= ll(A); --I)
#define TO(x,t,f) ((x)?(t):(f))
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //xi>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //xi>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd(ll a,ll b){if(a%b==0)return b;return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=ll(1e16)+ll(7);
const ll MOD=1000000007LL;
#define out(a) cout<<fixed<<setprecision((a))
//tie(a,b,c) = make_tuple(10,9,87);
#define pop(a) __builtin_popcount((a))
ll keta(ll a){ll r=0;while(a){a/=10;r++;}return r;}
ll ketawa(ll a){ll r=0;while(a){r+=a%10;a/=10;}return r;}


template <typename T>
class Seg_Tree{
public: // 0-index
  vector<T> dat;
  T initial,M;
  int n;
  T unite(T a,T b){//
    return min(a,b);
  }
  Seg_Tree(int n0_=1,T initial_=1,T M_=1){
    initsize(n0_,initial_,M_);
  }
  void initsize(int n0,T initial_,T M_){
    M = M_;
    initial = initial_;
    int k=1;
    while(1){
      if(n0<=k){
        n=k;
        dat.resize(2*n-1);
        for(int i=0;i<2*n-1;i++)dat[i]=initial;
        break;
      }
      k*=2;
    }
  }
 
  //i banme wo x nisuru
  void update(int i,T x){
    i += n-1;
    dat[i] = x;
    while(i>0){
      i = (i-1) / 2;
      dat[i] = unite(dat[i*2+1],dat[i*2+2]);
    }
  }
 
  //[a,b)
  T query0(int a,int b,int k,int l,int r){
    if(r<=a || b<=l)return initial;
    if(a<=l && r<=b)return dat[k];
    else{
      T vl = query0(a,b,k*2+1,l,(l+r)/2);
      T vr = query0(a,b,k*2+2,(l+r)/2,r);
      return unite(vl,vr);
    }
  }
 
  //return unite[a,b)
  T query(int a,int b){
    return query0(a,b,0,0,n);
  }
};

int main(){
	ll N,M;
	string S;
	cin >> N >> M >> S;

	Seg_Tree<ll> sg(N+2,MOD,MOD+5);
	FOR(i,0,N+1)if(S[i]=='0')sg.update(i,i);
	vector<ll> ans;
	ll now = N;
	while(now){
		ll to = sg.query(now-M,now);
		if(to == MOD){
			cout << -1 << endl;
			return 0;
		}
		ans.push_back(now - to);
		now = to;
	}
	REV(ans);
	cout << ans[0];
	FOR(i,1,ans.size()){
		cout << " " << ans[i];
	}
	cout << endl;
}