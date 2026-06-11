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
const ll INF=1e17;
const long double PI=acos(-1);



void solve(int T){
    int n;
    cin>>n;
    int c=0;
    for(int i=1;i*i<n;i++){
        for(int j=i;j*i<n;j++){
            if(j!=i)c+=2;
            else c++;
        }
    }
    cout<<c;
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
/*

for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            cout<<i<<" "<<j<<" "<<n-(i*j)<<"\n";
        }
    }
    */
