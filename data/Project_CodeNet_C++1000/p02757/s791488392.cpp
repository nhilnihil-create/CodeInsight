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
	int n,p;
	ll ans=0;
	cin >>n>>p;
	string s;
	cin>>s;
	map<ll,ll>dis;
	if(p==2){
		for(int i=0;i<s.size();i++){
			if((s[i]-'0')%2==0){
				ans+=i+1;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if (p == 5)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if ((s[i] - '0') % 5 == 0)
			{
				ans += i + 1;
			}
		}
		cout << ans << endl;
		return 0;
	}
	ll base=1LL;
	ll cnt=0LL;
	dis[0]=1;
	for(int i=s.size()-1;i>=0;i--){
		cnt+=(base*(s[i]-'0'))%p;
		cnt%=p;
	//	clog<<cnt<<endl;
		dis[cnt]+=0;
		dis[cnt]++;
		base*=10LL;
		base%=p;

	}
	repi(itr,dis){
		
			ans+=(itr->S)*(-1+itr->S)/2;
		
	}
	cout<<ans<<endl;
}
/*
15938532
*/