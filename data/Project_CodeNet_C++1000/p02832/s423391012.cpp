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
const int MOD2=15000007;
const ll MAX=9187201950435737471;
const int N=100005;
const int INF=1e17;
const long double PI=acos(-1);

vector<int>v[2*N];

void solve(int T){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        v[a[i]].pb(i);
    }
    int ans=0,lst=-1;
    for(int i=1;i<=n;i++){
        //cout<<lst<<"\n";
        if(v[i].empty() && ans==0){
            cout<<"-1\n";
            return;
        }
        if(v[i].empty() && ans>0){
            cout<<n-ans<<"\n";
            return;
        }
        auto it=upper_bound(v[i].begin(),v[i].end(),lst);
        if(it!=v[i].end()){
            lst=*it;
            ans++;
            continue;
        }
        if(it==v[i].end() && ans==0){
            cout<<"-1\n";
            return;
        }
        if(it==v[i].end() && ans>0){
            cout<<n-ans<<"\n";
            return;
        }
    }
    cout<<n-ans<<"\n";
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



