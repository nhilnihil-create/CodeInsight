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
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

void solve(){
    long n,m;
    cin>>n>>m;
    long Wa[n+2];
    vector<bool > Ac(n+2,false);
    memset(Wa,0,sizeof(Wa));
    for(int i=0;i<m;i++){
        long x;
        cin>>x;
        string s;
        cin>>s;
        if(s=="WA"){
            if(!Ac[x]){
                Wa[x]++;
            }
        } else {
            Ac[x]=true;
        }
    }
    long TotAC=0,TotWA=0;
    for(int i=0;i<n+2;i++){
        if(Ac[i]){
            TotAC++;
            TotWA+=Wa[i];
        }
    }
    cout<<TotAC<<" "<<TotWA<<endl;
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