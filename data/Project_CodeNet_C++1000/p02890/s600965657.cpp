#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

#define ld long double
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

/* Some Libraries */

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    vi p(n);
    rep(i,n){
        int a; cin>>a;
        p[a-1]++;
    }
    sort(all(p));
    vi sum(n+1,0);
    rep(i,n) sum[i+1]=sum[i]+p[i];
    FOR(k,1,n){
        int l=0, r=n/k+1; //L OK, R NG
        while(r-l>1){
            int mid = (l+r)/2;
            int itr = lower_bound(all(p),mid)-p.begin();
            ll val = sum[itr]+(n-itr)*mid;
            if (val>=mid*k){
                l = mid;
            }else{
                r = mid;
            }
        }
        cout<<l<<"\n";
    }
    return 0;
}
