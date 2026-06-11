#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define pb push_back
#define fi first
#define se second
#define ld long double
#define vi vector<vector<ll> >
using namespace std;
const int MOD=1000000007;
const int MOD2=998244353;
const ll MAX=9187201950435737471;
const int N=100005;
const int INF=1e9+7;
const long double PI=acos(-1);



void solve(int T){
    int n,d;
    cin>>n>>d;
    vector<vector<int> >a(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            int x;
            cin>>x;
            a[i].pb(x);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double x=0.0;
            for(int k=0;k<d;k++){
                x+=(a[i][k]-a[j][k])*(a[i][k]-a[j][k]);
            }
            x=sqrt(x);
            if(floor(x)==ceil(x))ans++;
        }
    }
    cout<<ans<<"\n";
}

int main() {
    fastio

    int T=1;
    //cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
        //if(i<T)cout<<"\n";
    }
    return 0;
}
