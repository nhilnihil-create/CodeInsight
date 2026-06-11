/*
 _ _ _   _    _   _    _   _ _ _   _    _   _ __ _   __       __
|  _ _| | |  | | | |  | | |  _  | | |  | | |  __  | |   \   /   |
| |_ _  | |__| | | |  | | | |_| | | |__| | | |__| | | |\ \_/ /| |
|_ _  | |  __  | | |  | | |  _ <  |  __  | |  __  | | | \   / | |
 _ _| | | |  | | | |__| | | |_| | | |  | | | |  | | | |  \_/  | |  _   _   _
|_ _ _| |_|  |_| |__ ___| |_ _ _| |_|  |_| |_|  |_| |_|       |_| |_| |_| |_|

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
#define MOD (int) 1e9+7
#define inf (int) (1e18)

void solve() {
    int n;
    cin>>n;
    double x[n],y[n];
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    long double fact[10];
    fact[0]=1;
    for(ll i=1;i<10;i++){
        fact[i]=fact[i-1]*i;
    }
    long double ans=0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            long double dis=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            ans+=dis*2.0;
        }
    }
    ans*=fact[n-1];
    ans/=fact[n];
    cout<<setprecision(12)<<ans<<endl;
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