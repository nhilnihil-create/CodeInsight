#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<iomanip>


using namespace std;
typedef long long ll;
typedef vector<ll> v;
typedef vector<vector<ll>> vv;


#define MOD 1000000007
#define INF 1001001001
#define MIN -1001001001
#define rep(i,k,N) for(int i=k;i<N;i++)
#define MP make_pair
#define MT make_tuple //tie,make_tuple は別物
#define PB push_back
#define PF push_front
#define all(x) (x).begin(),(x).end()


int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


int main(){
    string S;
    cin>>S;
    ll N = S.size();
    vector<vector<ll>> dp(2,v(N+1));

    dp[1][0] = 1;
    dp[0][0] = 0;
    rep(i,0,N){
        ll now = ll(S[i]-'0');
        dp[0][i+1] = min(dp[1][i] + 10 - now, dp[0][i] + now); 
        dp[1][i+1] = min({dp[0][i] + now + 1, dp[1][i] + 10 - now - 1 }); 
    }
    cout<<dp[0][N];
    return 0;
}