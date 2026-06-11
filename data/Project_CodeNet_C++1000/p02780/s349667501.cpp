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

double A[200005];

void solve(int T){
    int n,k;
    double res,ex=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<k;i++)
    {
        ex+=(A[i]*(A[i]+1)/2)*(1/A[i]);
    }
    res=ex;
    for(int i=k;i<n;i++)
    {
        ex-=(A[i-k]*(A[i-k]+1)/2)*(1/A[i-k]);
        ex+=(A[i]*(A[i]+1)/2)*(1/A[i]);
        res=max(res,ex);
    }
    cout<<fixed<<setprecision(12)<<res<<endl;
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



