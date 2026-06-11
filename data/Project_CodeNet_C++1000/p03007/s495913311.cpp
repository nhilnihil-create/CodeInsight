#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

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
    int N; cin>>N;
    vi a(N);
    rep(i,N) cin>>a[i];
    sort(all(a));
    int n=1,p=1;
    FOR(i,1,N-2){
        if (a[i]<0) n++; else p++;
    }
    ll now;
    vector<pi> ope;
    if (p==1){
        now = a.back();
        rep(i,N-1){
            ope.pb({now,a[i]});
            now-=a[i];
        }
    }else{
        now = a.front();
        rep(i,p-1){
            ope.pb({now,a[N-i-1]});
            now-=a[N-i-1];
        }
        ope.pb({a[N-p],now});
        now = a[N-p]-now;
        rep(i,n-1){
            ope.pb({now,a[i+1]});
            now-=a[i+1];
        }
    }
    cout<<now<<endl;
    rep(i,N-1){
        cout<<ope[i].fi<<" "<<ope[i].se<<endl;
    }
    return 0;
}
