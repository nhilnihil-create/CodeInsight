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
	int n,k;
	ll ans=0LL;
	cin >>n>>k;
	int r,s,p;
	cin>>r>>s>>p;
	string t;
	cin>>t;
	int fin;
	vector<vector<ll>>dp(n/k+2,vector<ll>(3,0LL));
	for(int i=0;i<k;i++){
	//	clog <<  n / k + (n % k > i ? 1 : 0)<<endl;
		for(int I=0;I<n/k+2;I++){
			for(int J=0;J<3;J++){
				dp[I][J]=0LL;
			}
		}
		fin = n / k + (n % k > i ? 1 : 0) ;
		for (int j = 0; j < n / k + (n % k > i ? 1 : 0); j++)
		{
			if(j!=0){
				dp[j][0]=max(dp[j-1][1],dp[j-1][2]);
				dp[j][1] = max(dp[j - 1][0], dp[j - 1][2]);
				dp[j][2] = max(dp[j - 1][1], dp[j - 1][0]);
			}
			switch(t[j*k+i]){
			case 'r':
				dp[j][0] += p;
				break;
			case 's':
				dp[j][1] += r;
				break;
			case 'p':
				dp[j][2] += s;
				break;
			}
		//	clog<<dp[j][0]<<" "<<dp[j][1]<<" "<<dp[j][2]<<endl;
		}
	//	clog<<dp[fin-1][0]<<" "<<dp[fin-1][1]<<" "<<dp[fin-1][2]<<endl;
		ans += max(dp[fin-1][0], max(dp[fin-1][1], dp[fin-1][2]));
		clog<<ans<<endl;
	}

	cout<<ans<<endl;
}