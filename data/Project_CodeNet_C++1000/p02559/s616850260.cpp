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
//--Binary Indexed Tree (Sum only)
//-------------------------------------------------
template<typename T>
class BIT
{
private:
    const int n;
    ::std::vector<T> data;
public:
    BIT(int n):n(n),data(n+1){
        for(int i=1; i<=n; i++) data[i] = 0;
    }
    BIT(const ::std::vector<T> &v):n(v.size()),data(n+1){
        for(int i=1; i<=n; i++) data[i] = v[i-1];
        for(int i=1; i<n; i++){
            int j = i+(i&-i);
            if(j<=n) data[j] += data[i];
        }
    }
    void add(int k, T x){k++;
        for(int i=k; i<=n; i+=i&-i) data[i] += x;
    }
    T query(int k){
        T ret=0;
        for(int i=k; i>0; i-=i&-i) ret += data[i];
        return ret;
    }
    T query(int a, int b){return query(b)-query(a);}
    void update(int k, T x){
        T upd = x-query(k, k+1);
        add(k, upd);
    }
    T operator[](int k){return query(k, k+1);}
};

//-------------------------------------------------

int main(void)
{
    int N,Q; cin>>N>>Q;
    vll a(N);
    rep(i,N) cin>>a[i];
    BIT<ll> bit(a);
    while(Q--){
        int t,x,y; cin>>t>>x>>y;
        if (t==0){
            bit.add(x,y);
        }else{
            cout<<bit.query(x,y)<<"\n";
        }
    }
    return 0;
}
