#include <bits/stdc++.h>
using namespace std;

#define MOD (1000000000+7)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define nl '\n'
#define all(x) x.begin(), x.end()
#define print(vec,l,r) for(int i = l; i <= r; i++) cout << vec[i] <<" "; cout << endl;
#define forf(i,a,b) for(int i = (a); i < (b); i++)
#define forr(i,a,b) for(int i = (a); i > (b); i--)
#define input(vec,N) for(int i = 0; i < (N); i++) cin >> vec[i];
#define debug(x) cerr << #x << " = " << (x) << endl;

// template starts
typedef long long int ll;

// template ends here

void solve(){
	// code starts from here
	ll S;
	cin >> S;
	//S = 2000;
	vector<ll> dp(S+1);
	dp[0] = 1;
	for(int i = 3; i <= S; i++){
		for(int j = 0; j <= i-3; j++){
			dp[i] += dp[j];
			dp[i] %= MOD;
		}
	}
	cout << dp[S] << endl;
}

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

int main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	//startTime = clock();
	
	int T;
	//cin >> T;
	T = 1;
	while(T--){
		solve();
	}
	
	//cerr << getCurrentTime() << endl;
	return 0;
}
