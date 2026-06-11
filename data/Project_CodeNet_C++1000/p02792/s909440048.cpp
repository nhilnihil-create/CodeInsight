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
const int INF=1e9;
const long double PI=acos(-1);

int a[11][11];

void solve(int T){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int j=i%10;
        int k=i;
        while(k>=10){
            k/=10;
        }
        a[k][j]++;
    }
    int ans=0;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            ans+=a[i][j]*a[j][i];
        }
    }
    cout<<ans<<"\n";
}

int main() {
    //fastio

    int T=1;
    //cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
        //if(i<T)cout<<"\n";
    }
    return 0;
}
