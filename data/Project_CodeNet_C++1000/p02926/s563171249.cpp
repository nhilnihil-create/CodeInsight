// #pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define N 1000000007
#define N2 998244353
#define nmax 200001
#define pll pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define fill_nums(A,n) for(ll i=0;i<n;i++) scanf("%lld",&A[i]);
#define fill_edges(adj,m) for(ll i=0;i<m;i++) {ll a, b; scanf("%lld %lld",&a,&b); adj[a-1].pb(b-1); adj[b-1].pb(a-1);}
#define fill_direct(adj,m) for(ll i=0;i<m;i++) {ll a, b; scanf("%lld %lld",&a,&b); adj[a-1].pb(b-1);}
#define PI 3.141592654

double findang(ll a_, ll b_) {
    if(!a_ && !b_) 
        return 0;
    double a = abs(a_), b = abs(b_);
    double ang = acos(a/sqrt(a*a+b*b));

    if(a_>=0 && b_<0)
        return 2*PI - ang;
    if(a_<0 && b_<=0)
        return PI + ang;
    if(a_<0 && b_>0)
        return PI - ang;
    return ang;
}

int main() {
    
    ll n; cin>>n;

    vector<pll> A(n);
    vector<pair<double, int>> angs(n);

    for(int i=0;i<n;i++) {
        cin>>A[i].first>>A[i].second;
        angs[i] = mp(findang(A[i].first, A[i].second), i);
    }

    sort(ALL(angs));

    ll maxi = 0;
    for(int i=0;i<n;i++) {
        ll x = 0;
        ll y = 0;

        // cout<<angs[i].first<<" "<<A[angs[i].second].first<<" "<<A[angs[i].second].second<<endl;

        for(int j=0;j<n;j++) {
            int idx = (i+j)%n;
            x += A[angs[idx].second].first;
            y += A[angs[idx].second].second;
            maxi = max(maxi, x*x+y*y);
        }
    }

    cout<<fixed<<setprecision(10);
    cout<<sqrt((double)maxi)<<endl;


    return 0;
}

