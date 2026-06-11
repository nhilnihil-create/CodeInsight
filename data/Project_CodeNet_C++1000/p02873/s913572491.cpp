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
#define ins insert

#define debug(a) cerr<<(a)<<endl
#define dbrep(a,n) rep(_i,n) cerr<<(a[_i])<<" "; cerr<<endl
#define dbrep2(a,n,m) rep(_i,n){rep(_j,m) cerr<<(a[_i][_j])<<" "; cerr<<endl;}

using namespace std;

template<class A, class B>
ostream &operator<<(ostream &os, const pair<A,B> &p){return os<<"("<<p.fi<<","<<p.se<<")";}
template<class A, class B>
istream &operator>>(istream &is, pair<A,B> &p){return is>>p.fi>>p.se;}

/* Some Libraries */

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; cin>>S;
    int N = S.size()+1;
    int mode=0; // up
    int cnt=0;
    vi vec;
    rep(i,N-1){
        if (mode==0 && S[i]=='<') cnt++;
        else if(mode==1 && S[i]=='>') cnt++;
        else if(mode==0 && S[i]=='>') vec.pb(cnt), cnt=1, mode=1;
        else if(mode==1 && S[i]=='<') vec.pb(cnt), cnt=1, mode=0;
    }
    vec.pb(cnt);
    int V = vec.size();
    ll ans=0;
    int now=0;
    rep(i,V){
        if (i&1){
            now = max(now,vec[i]);
            ans+=now;
            ans+=(ll)(vec[i]-1)*vec[i]/2;
            now=0;
        }else{
            ans+=(ll)(now+vec[i]-1)*vec[i]/2;
            now+=vec[i];
        }
    }
    ans+=now;
    cout<<ans<<endl;
    return 0;
}
