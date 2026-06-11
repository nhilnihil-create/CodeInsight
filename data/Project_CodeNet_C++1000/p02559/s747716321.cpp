#include <bits/stdc++.h>
#include <atcoder/all>
#define int long long
#define endl "\n" // fflush(stdout);
#define ALL(v) (v).begin(),(v).end()
#define Vi vector<int>
#define VVi vector<Vi>
#define VVVi vector<VVi>
#define Vm vector<mint>
#define Vs vector<string>
#define Vd vector<double>
#define Vc vector<char>
#define Pii pair<int,int>
#define Pdd pair<double,double>
#define VPii vector<Pii>
#define Tiii tuple<int,int,int>
#define VTiii vector<Tiii>
#define PQi priority_queue<int>
#define PQir priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define itos to_string
#define stoi stoll
#define FI first
#define SE second
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define cyes cout<<"yes"<<endl
#define cno cout<<"no"<<endl
#define sortr(v) sort(v,greater<>())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define repreq(i,a,b) for(int i=a;i>=b;i--)
#define dem(a,b) ((a+b-1)/(b))
#define INF 3000000000000000000 // 3.0*10^18
#define MAX LLONG_MAX
#define PI acos(-1.0L)
const int MOD = 998244353; // case
//const int MOD = 1000000007; // 10^9 + 7
const double EPS = 1e-6;

using namespace std;
using namespace atcoder;

/* debug */
template <typename T> // vector
ostream& operator<<(ostream& os,const vector<T> &V){int N=V.size();
if(N==0){os<<'.';return os;}rep(i,0,N-1){os<<V[i]<<' ';}os<<V[N-1];return os;}
template <typename T> // vector vector
ostream& operator<<(ostream& os,const vector<vector<T>> &V){
int N=V.size();rep(i,0,N-1)cout<<V[i]<<endl;cout<<V[N-1];return os;}
template <typename T,typename S> // pair
ostream& operator<<(ostream& os, pair<T,S> const&P){os<<P.FI<<' '<<P.SE;return os;}
template <typename T> // set
ostream& operator<<(ostream& os,set<T> &S){auto it=S.begin();while(it!=S.end()){
os<<*it;if(next(it,1)!=S.end())os<<' ';it++;};return os;}
template <typename T> // deque
ostream& operator<<(ostream& os, deque<T> &q){for(auto it=q.begin();it<q.end();it++){
os<<*it;if(it+1!=q.end())os<<" ";}return os;}

/* useful */
template<typename T>void Vin(vector<T> &v){int n=v.size();rep(i,0,n)cin>>v[i];}
int scomb(int n, int r){if(r<0||r>n)return 0;if((n-r)<r)r=n-r; // nCr
int a=1;for(int i=n;i>n-r;--i){a=a*i;}for(int i=1;i<r+1;++i){a=a/i;}return a;}
Vi vis(Vi &v){Vi S(v.size()+1);rep(i,1,S.size())S[i]+=v[i-1]+S[i-1];return S;}
int digit_sum(int n){int ret=0; while(n>0){ret+=n%10;n/=10;}return ret;}
int digit(int k,int i){string s = itos(k);return s[s.size()-i]-'0';} // i桁目の数字
template<typename T>void press(T &v){v.erase(unique(ALL(v)),v.end());} // 圧縮
Vi zip(Vi b){int Z=b.size(); // 座標圧縮
Pii p[Z+10];int a=b.size();Vi l(a);for(int i=0;i<a;i++)
p[i]=mp(b[i],i);sort(p,p+a);int w=0;for(int i=0;i<a;i++)
{if(i&&p[i].first!=p[i-1].first)w++;l[p[i].second]=w;}return l;}
Vi nibe2V(){Vi a(60);int q = 1;rep(i,0,60){a[i]=q;q*=2;}return a;}
//Vi nibe = nibe2V(); // 2^n
int modiv(int a,int b){return a*pow_mod(b,MOD-2,MOD)%MOD;} // a÷b(%MOD)
int SMALLER(Vi &a,int x){return lower_bound(a.begin(),a.end(),x)-a.begin();}
int orSMALLER(Vi &a,int x){return upper_bound(a.begin(),a.end(),x)-a.begin();}
int BIGGER(Vi &a,int x){return a.size()-orSMALLER(a,x);}
int orBIGGER(Vi &a,int x){return a.size()-SMALLER(a,x);}
int COUNT(Vi &a,int x) {return upper_bound(ALL(a),x)-lower_bound(ALL(a),x);}
int maxind(Vi &a){return max_element(ALL(a))-a.begin();}
int minind(Vi &a){return min_element(ALL(a))-a.begin();}
Vi stpowV(){Vi a(1000005);a[0]=1;repeq(i,1,1000004)a[i]=a[i-1]*i%MOD;return a;}
//Vi stpow = stpowV(); // 階乗配列(%MOD)

/****************************** START ******************************/

using mint = static_modint<MOD>;
template <typename X>
struct SegTree {
    using FX = function<X(X, X)>; // X•X -> X となる関数の型
    int n;
    FX fx;
    const X ex;
    vector<X> dat;
    SegTree(int n_, FX fx_, X ex_) : n(), fx(fx_), ex(ex_), dat(n_ * 4, ex_) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }

    void set(int i, X x) { dat[i + n - 1] = x; }
    void build() {
        for (int k = n - 2; k >= 0; k--) dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
    }

    void update(int i, X x) {
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;  // parent
            dat[i] = fx(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }

    X query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    X query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return ex;
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return fx(vl, vr);
        }
    }
    X operator[](int i) {
        return dat[i + n - 1];
    }
};
/* 
     SegTree<X>(n,fx,ex): モノイド(集合X, 二項演算fx, 単位元ex)についてサイズnで構築
     set(int i, X x), build(): i番目の要素をxにセット。まとめてセグ木を構築する。O(n)
     update(i,x): i 番目の要素を x に更新。O(log(n))
     query(a,b): [a,b) 全てにfxを作用させた値を取得。O(log(n))
 */

signed main() {
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(12);
  int n,q;cin >> n >> q;
  auto fsum = [](int a,int b){return a+b;};
  SegTree<int> st(n,fsum,0);
  
  rep(i,0,n){
    int qw;cin >> qw;
    st.set(i,qw);
  }
  st.build();
  
  rep(i,0,q){
    int qw,er,ty;cin >> qw >> er >> ty;
    if(qw){
      cout << st.query(er,ty) << endl;
    }
    else {
      st.update(er,ty+st[er]);
    }
  }
  return 0;
}