#include "bits/stdc++.h"

#define REP(i,num) for(ll i=0;i<(num);++i)
#define FOR(i,c,num) for(ll (i)=(c);(i)<(num);++(i))
#define LOOP(i) while(i--)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto pitr=c.begin();pitr!=c.end();++pitr){cout<<*pitr;if(next(pitr,1)!=c.end())cout<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;

constexpr ll atcoder_mod = 1e9+7;

template<typename T=ll>
T in(){T x; cin >> x; return (x);}
template<typename T=ll,typename C=vector<T>>
C vecin(int N){C x(N);REP(i,N){x[i]=in<T>();}return x;}

void vout(){cout << endl;}
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){cout << ' ' << h;vout(forward<Tail>(t)...);}
void out(){cout << endl;}
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){cout << h;vout(forward<Tail>(t)...);}

template<typename T>
bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>
bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}

/* 処理：範囲加算　出力：範囲合計値
auto fx = [](ll x1, ll x2){ return x1 + x2; };
auto fa = [](ll x, ll m){ return x + m; };
auto fm = [](ll m1, ll m2){ return m1 + m2; };
auto fp = [](ll m, ll n){ return m * n; };
long long ex = 0;
long long em = 0;
*/

/* 処理：範囲加算　出力：範囲最小値
auto fx = [](ll x1, ll x2){ return min(x1 , x2); };
auto fa = [](ll x, ll m){ return x + m; };
auto fm = [](ll m1, ll m2){ return m1 + m2; };
auto fp = [](ll m, ll n){ return m; };
long long ex = numeric_limits<ll>::max();
long long em = 0;
*/

/* 処理：範囲変更　出力：範囲最小値
auto fx = [](ll x1, ll x2){ return min(x1 , x2); };
auto fa = [](ll x, ll m){ return m; };
auto fm = [](ll m1, ll m2){ return m2; };
auto fp = [](ll m, ll n){ return m; };
long long ex = numeric_limits<ll>::max();
long long em = numeric_limits<ll>::max();
*/

/*
auto fx = [](ll x1, ll x2){ return x1 + x2; };
auto fa = [](ll x, ll m){ return m; };
auto fm = [](ll m1, ll m2){ return m2; };
auto fp = [](ll m, ll n){ return m*n; };
long long ex = 0;
long long em = numeric_limits<ll>::max();
*/

class RangeUpdate{
public:
	virtual ll fa(ll x,ll m)=0;
	virtual ll fm(ll m1,ll m2)=0;
	ll em;
};

class RangeUpdateChange:public RangeUpdate{
public:
	RangeUpdateChange(){em = numeric_limits<ll>::max();}
	ll fa(ll x,ll m){return m;}
	ll fm(ll m1,ll m2){return m2;}
};

class RangeUpdateAdd:public RangeUpdate{
public:
	RangeUpdateAdd(){em = 0;}
	ll fa(ll x,ll m){return x+m;}
	ll fm(ll m1,ll m2){return m1+m2;}
};

class RangeQuery{
public:
	virtual ll fx(ll x1,ll x2)=0;
	virtual ll fp(ll m,ll n)=0;
	ll ex;
};

class RangeQuerySum:public RangeQuery{
public:
	RangeQuerySum(){ex=0;}
	ll fx(ll x1,ll x2){return x1+x2;}
	ll fp(ll m,ll n){return m*n;}
};

class RangeQueryMin:public RangeQuery{
public:
	RangeQueryMin(){ex = numeric_limits<ll>::max();}
	ll fx(ll x1,ll x2){return min(x1,x2);}
	ll fp(ll m,ll n){return m;}
};

class RangeQueryBitSum:public RangeQuery{
public:
	RangeQueryBitSum(){ex = 0;}
	ll fx(ll x1,ll x2){return x1 | x2;}
	ll fp(ll m,ll n){return m;}
};

class SegmentTree{
	unique_ptr<RangeUpdate> range_update;
	unique_ptr<RangeQuery> range_query;

	/* lazy eval */
	void Eval(int k,int len){
		if(lazy[k]==range_update->em) return;  // 更新するものが無ければ終了
		if(k<size-1){            // 葉でなければ子に伝搬
			lazy[k*2+1] = range_update->fm(lazy[k*2+1],lazy[k]);
			lazy[k*2+2] = range_update->fm(lazy[k*2+2],lazy[k]);
		}
		// 自身を更新
		dat[k] = range_update->fa(dat[k],range_query->fp(lazy[k],len));
		lazy[k] = range_update->em;
	}

	ll Query(ll a, ll b, ll k, ll l, ll r){
		Eval(k,r-l);
		if(r<=a || b<=l){  // 完全に外側の時
			return range_query->ex;
		}
		else if(a <= l && r <= b){  // 完全に内側の時
			return dat[k];
		}
		else{  // 一部区間が被る時
			ll vl = Query(a,b,k*2+1,l,(l+r)/2);
			ll vr = Query(a,b,k*2+2,(l+r)/2,r);
			return range_query->fx(vl,vr);
		}
	}

	void Update(ll a, ll b, ll x, ll k, ll l, ll r) {
		Eval(k,r-l);
		if(a<=l && r<=b){  // 完全に内側の時
			lazy[k] = range_update->fm(lazy[k],x);
			Eval(k,r-l);
		}
		else if(a<r && l<b){                     // 一部区間が被る時
			Update(a,b,x,k*2+1,l,(l+r)/2);  // 左の子
			Update(a,b,x,k*2+2,(l+r)/2,r);  // 右の子
			dat[k] = range_query->fx(dat[k*2+1],dat[k*2+2]);
		}
	}
public:
	ll size;
	vector<ll> dat;
	vector<ll> lazy;
	SegmentTree(ll N, unique_ptr<RangeUpdate> rup,unique_ptr<RangeQuery> rqp)
		: range_update(std::move(rup)), range_query(std::move(rqp)){
		dat.resize(4*N,range_query->ex);
		lazy.resize(4*N,range_update->em);
		ll x = 1;
		while(N>x) x *= 2;
		size = x;
	}
	void Set(int i,ll x){dat[i+size-1]=x;}
	void Build(){
		for(ll k=size-2ll;k>=0;k--) dat[k] = range_query->fx(dat[2*k+1],dat[2*k+2]);
	}
	
	void Update(ll a, ll b, ll x){Update(a, b, x, 0, 0, size);}
	ll Query(int a, int b){return Query(a, b, 0, 0, size);}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	auto N=in(),D=in(),A=in();
	vector<pair<ll,ll>> X(N);

	SegmentTree Seg(N,make_unique<RangeUpdateAdd>(),make_unique<RangeQueryMin>());
	REP(i,N){
		X[i].first=in();
		X[i].second=in();
	}
	sort(ALL(X),PAIRCOMP(first,<));
	REP(i,N){
		Seg.Set(i,X[i].second);
	}
	Seg.Build();

	ll S=0;
	REP(i,N){
		auto C=Seg.Query(i,i+1);
		if(C<=0) continue;

		ll M = (C+A-1ll)/A;
		S += M;

		ll R=X[i].first+2ll*D;
		auto res = upper_bound(ALL(X),make_pair(R,0),PAIRCOMP(first,<));
		auto L = distance(X.begin()+i,res);
		Seg.Update(i,i+L,-M*A);
	}
	out(S);
	return 0;
}
