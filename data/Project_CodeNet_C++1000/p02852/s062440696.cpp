#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,int> Pi;
#define rep(i,n) for(ll i=0;i<n;i++)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define fi first
#define se second

template<typename T> inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<typename T> ostream& operator<<(ostream& s,const complex<T>& d) {return s<<"("<<d.real()<<", "<<d.imag()<< ")";}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const pair<T1,T2>& d) {return s<<"("<<d.first<<", "<<d.second<<")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& d){int len=d.size();rep(i,len){s<<d[i];if(i<len-1) s<<" ";}return s;}
template<typename T> ostream& operator<<(ostream& s,const vector<vector<T>>& d){int len=d.size();rep(i,len){s<<d[i]<<endl;}return s;}
template<typename T> ostream& operator<<(ostream& s,const set<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const map<T1,T2>& m){s<<"{"<<endl;for(auto itr=m.begin();itr!=m.end();++itr){s<<" "<<(*itr).first<<" : "<<(*itr).second<<endl;}s<<"}"<<endl;return s;}

const ll mod=1e9+7;
const ll inf=1e17;
const int INF=1e9;
const double PI=acos(-1);
const double EPS=1e-10;

template<typename Monoid,typename F>
struct SegmentTree{
	int sz;
	vector<Monoid> node;
	const F op;//演算
	const Monoid e;//単位元
	SegmentTree(int n,const F op,const Monoid &e):op(op),e(e){
		sz=1;
		while(sz<n) sz*=2;
		node.assign(2*sz,e);
	}
	void build(const vector<Monoid> &v){
		int n=v.size();
		for(int i=0;i<n;i++) node[i+sz-1]=v[i];
		for(int i=sz-2;i>=0;i--) node[i]=op(node[2*i+1],node[2*i+2]);
	}
	void update(int k,const Monoid &x){
		k+=sz-1;
		node[k]=x;
		while(k>0){
			k=(k-1)/2;
			node[k]=op(node[2*k+1],node[2*k+2]);
		}
	}
	Monoid query(int a,int b,int k=0,int l=0,int r=-1){
		if(r<0) r=sz;
		if(r<=a || b<=l) return e;
		if(a<=l && r<=b) return node[k];
		else{
			Monoid vl=query(a,b,2*k+1,l,(l+r)/2);
			Monoid vr=query(a,b,2*k+2,(l+r)/2,r);
			return op(vl,vr);
		}
	}
	Monoid operator[](const int &k)const{
		return node[k+sz-1];
	}
};

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	auto op=[](int a,int b){return min(a,b);};
	SegmentTree<int,decltype(op)> seg(3*n,op,INF);
	vector<int> dp(3*n,INF);
	dp[n]=0;
	seg.build(dp);
	for(int i=n-1;i>=0;i--){
		if(s[i]=='1') continue;
		int now=seg.query(i+1,i+m+1);
		if(now==INF) continue;
		dp[i]=now+1;
		seg.update(i,dp[i]);
	}
	if(dp[0]==INF){
		cout<<-1<<endl;
		return 0;
	}
	vector<int> ans;
	int ind=0,now=dp[0];
	FOR(i,1,n+1){
		if(dp[i]==now-1){
			ans.push_back(i-ind);
			ind=i;
			now--;
		}
	}
	cout<<ans<<endl;
}