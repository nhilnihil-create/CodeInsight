#include <bits/stdc++.h>
using namespace std;

#define MOD 10000007
#define f first
#define s second
#define es " "
#define pb push_back
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define ll long long int
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

ll dp[3005][6005];
int n;
pair<int, int> v[3005];

ll solve(int obj, int time){
    if(dp[obj][time]!=-1){
        return dp[obj][time];
    }
    if(obj>n){
        return dp[obj][time]=0;
    }
    ll nao, pega;
    nao=solve(obj+1, time);
    if(time>3000){
        pega=solve(obj+1, time-v[obj].f)+v[obj].s;
        return dp[obj][time]=max(pega, nao);
    }
    return dp[obj][time]=nao;
}

int main(){
    fastio;
    int t;
    memset(dp, -1, sizeof(dp));
    cin >> n >> t;
    for(int i=1; i<=n; i++){
        cin >> v[i].f >> v[i].s;
    }
    sort(v+1, v+n+1);
    cout << solve(1, 3000+t) << endl;
    return 0;
}