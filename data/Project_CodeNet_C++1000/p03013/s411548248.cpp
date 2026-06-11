#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i )
typedef std::pair<int,int> pint;

using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> list(N+1,true);
    rep (i,M){
        int tmp;
        cin >> tmp;
        list[tmp] = false;
    }
    vector<ll> dp(N+1);
    dp[0] = 1;
    for (int now = 0; now < N; now++){
        for (int next = now + 1;next <= min(N,now+2); next++){
            if(list[next]){
                dp[next] += dp[now];
                dp[next] %= mod;
            }
        }
    }
    cout << dp[N] << endl;
    return 0;
}