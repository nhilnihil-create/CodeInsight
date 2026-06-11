/*
 _ _ _   _    _   _    _   _ _ _   _    _   _ __ _   __       __
|  _ _| | |  | | | |  | | |  _  | | |  | | |  __  | |   \   /   |
| |_ _  | |__| | | |  | | | |_| | | |__| | | |__| | | |\ \_/ /| |
|_ _  | |  __  | | |  | | |  _ <  |  __  | |  __  | | | \   / | |
 _ _| | | |  | | | |__| | | |_| | | |  | | | |  | | | |  \_/  | |  _   _   _
|_ _ _| |_|  |_| |_ __ _| |_ _ _| |_|  |_| |_|  |_| |_|       |_| |_| |_| |_|

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fi first
#define se second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(a) cout << #a << " = " << a << " ";
#define endl "\n"
const int  MOD=1000000007;
const int N=1000100;

void solve(){
    ll N,k;
    cin>>N>>k;
    ll R,S,P;
    cin>>R>>S>>P;
    string mov;
    cin>>mov;
    ll dp[N+2];
    dp[0]=0;
    for(int i=0;i<N;i++){
        if(i<k){
            dp[i+1]=dp[i]+(mov[i]=='r')*P+(mov[i]=='s')*R+(mov[i]=='p')*S;
        } else {
            if(mov[i]=='r' && mov[i-k]=='r') mov[i]='t';
            else if(mov[i]=='s' && mov[i-k]=='s') mov[i]='t';
            else  if(mov[i]=='p' && mov[i-k]=='p') mov[i]='t';
            dp[i+1]=dp[i]+(mov[i]=='r' && mov[i-k]!='r')*P+(mov[i]=='s' && mov[i-k]!='s')*R+(mov[i]=='p' && mov[i-k]!='p')*S;
        }
    }
    cout<<dp[N]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t = 1;
    // cin>>t;
    for (long int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}
