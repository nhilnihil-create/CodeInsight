#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
clock_t startTime;
long double getTime(){
	return (long double)(clock()-startTime)/CLOCKS_PER_SEC;
}

ll mod=1e9+7;
ll dp[2001][2001] ;
ll C(int n, int i){
	if(dp[n][i]!=-1) return dp[n][i];
	if(n < i) return (dp[n][i]=0);
	if(n==i || i==0) return (dp[n][i]=1LL);
	else return (dp[n][i] = (C(n-1,i-1) + C(n-1,i))%mod);
	
}



int main(){
	startTime=clock();
	ll n,k;
	cin >> n >> k;
	FOR(i,2001)
		FOR(j,2001) dp[i][j]=-1;
	//cout << C(n,k);
	for(int i=1;i <=k;i++){
		cout << (C(k-1,i-1) * C(n-k+1,i))% mod <<"\n";
	}

	return 0;
}