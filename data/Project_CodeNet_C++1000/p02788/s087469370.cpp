#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define repi(i,x) for(auto i=(x).begin(),i##_fin=(x).end();i!=i##_fin;i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a)?"Yes":"No")
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int , int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<60;
const int INF = 1<<30;
const double PI=acos(-1);
int main(){
	int n,a;
	ll d;
	ll ans=0;
	cin >>n>>d>>a;
	VP q(n+1);//x,h
	VP dis(n, mp(0LL, 0LL));
	rep(i,n){
		cin>>q[i].F>>q[i].S;
		dis[i].F=q[i].F;
	}
	q[n]=mp(INFLL,0LL);
	sort(all(q));
	sort(all(dis));
	auto ter=dis.begin();
	ll cnt=0LL;
	for(int i=0;i<n;i++){
		if(i!=0){
			dis[i].S+=dis[i-1].S;
		}
		cnt=max(0LL,(q[i].S-dis[i].S+a-1)/(a));
		//clog<<dis[i].F<<" "<<cnt<<endl;
		dis[i].S+=cnt*a;
		ans+=cnt;
		ter=upper_bound(all(dis),mp(dis[i].F+d*2,INFLL));
		if(ter!=dis.end()){
		ter->S-=a*cnt;
		}
		
	}
	cout<<ans<<endl;
}