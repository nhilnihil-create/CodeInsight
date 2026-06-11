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
    int a,b,c,k;
    cin>>a>>b>>c>>k;
    while(b<=a && k>0){
        b*=2;
        k--;
    }
    while(c<=b && k>0){
        c*=2;
        k--;
    }
    if(a<b && b<c){
        cout<<"Yes\n";
    }
    else cout<<"No\n";
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


