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

//-------------------------------------------------
//--Sieve of Eratosthenes
//-------------------------------------------------
class Sieve
{
private:
    ::std::vector<bool> prime;
public:
    Sieve(int n):prime(n+1, true){
        prime[0] = prime[1] = false;
        for(int i=2; i*i<=n; i++){
            if (!prime[i]) continue;
            for(int j=i*2; j<=n; j+=i){
                prime[j] = false;
            }
        }
    }
    bool isprime(int x){return prime[x];}
};

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    Sieve sieve((int)1e6);
    int X; cin>>X;
    while(true){
        if (sieve.isprime(X)) break;
        X++;
    }
    cout<<X<<endl;
    return 0;
}
