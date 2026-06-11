#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vint;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<vector<int>> vvint;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<ll, ll>> vpll;
typedef priority_queue<int, vector<int>, greater<int>> spqint; //小さい順に取り出し
typedef priority_queue<ll, vector<ll>, greater<ll>> spqll;     //小さい順に取り出し
typedef priority_queue<int, vector<int>, less<int>> bpqint;    //大きい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll>> bpqll;        //大きい順に取り出し

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define IREP(i, v) for (auto i = (v).begin(); i != (v).end(); i++)
#define FI first
#define SE second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PF push_front
#define TS to_string
#define BS binary_search
#define LB lower_bound
#define UB upper_bound
#define NP next_permutation
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) (ll) x.size()
#define SP(x) setprecision((ll)x)


int INF = 1e9;
int NIL = -1;
ll MOD = 1000000007;
ll LINF = 1e18;
double EPS = 1e-9;
double PI = M_PI;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; } //最大公約数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }     //最小公倍数

void yes(){ cout << "Yes" << endl;}
void no(){ cout << "No" << endl;}
//-----------------------------------------
struct UnionFind {
  vint par ;  //iの親
  vint rank ; //木の深さ
  vll siz ; //iの属する集合の要素数
  
  //n要素の初期化
  void init(int n){
    REP(i,n){
      par.PB(i) ;
      rank.PB(0) ;
      siz.PB(1) ;
    }
  }
  
  //木の根を求める
  //根が一緒なら同じ集合と判断するため
  int find(int x){
    if(par[x]==x){
      return x ;
    }
    else{
      return par[x] = find(par[x]) ;
    }
  }
  
  //木の併合
  //記録してあるrankをもとに併合
  void unite(int x,int y){
    x = find(x) ;
    y = find(y) ;
    if(x==y){
      return ;
    }
    
    if(rank[x] < rank[y]){
      par[x] = y ;
      siz[y] += siz[x] ;
    }
    else{
      par[y] = x ;
      siz[x] += siz[y] ;
      if(rank[x]==rank[y]){
        rank[x]++ ;
      }
    }
  }
  
  //xとyが同じ集合に属するか
  bool same(int x,int y){
    return find(x) == find(y) ;
  }
  
  //iが根であるかを返す
  bool root(int x){
    return x==find(x) ;
  }
    
  
  //xの属する集合の要素数を返す
  ll size(int x){
    return siz[find(x)] ;
  }
  
  //グラフ全体で何個の集合があるか返す
  ll cnt(int n){
    ll res = 0 ;
    REP(i,n){
      if(i==find(i)){
        res++ ;
      }
    }
    return res ;
  }
  
};
//-----------------------------------------
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::chrono::system_clock::time_point start,end;
    start = std::chrono::system_clock::now();

    ll n ;
    cin >> n ;
    vpll poi(n) ;
    REP(i,n){
        cin >> poi[i].FI >> poi[i].SE ;
    }
    sort(ALL(poi)) ;
    vll x(n) ;
    vll y(n) ;  
    REP(i,n){
        x[i] = poi[i].FI ;
        y[i] = poi[i].SE ;
    }
    map<pll,ll> Map ;
    REP(i,n-1){
        FOR(j,i+1,n){
            ll xp = x[i] - x[j] ;
            ll yp = y[i] - y[j] ;
            Map[MP(xp,yp)]++ ;
        }
    }

    ll maxi = 0 ;
    pll hoge ;
    IREP(i,Map){
        if(maxi<=i->SE){
            maxi = i->SE ;
            hoge = i->FI ;
        }
        //cout << i->FI.FI << " "<< i->FI.SE <<" "<< i->SE <<endl;
    }

    ll ans = n ;

    REP(i,n-1){
        FOR(j,i+1,n){
            pll temp ;
            ll xp = x[i] - x[j] ;
            ll yp = y[i] - y[j] ;
            temp = MP(xp,yp) ;

            if(temp==hoge){
                ans-- ;
            }            
        }
    }

    cout << ans <<endl;
    

    

    
    end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast< std::chrono::milliseconds >(end - start).count();
    //std::cout << elapsed <<"ms"<< std::endl;

    

    return 0;
}

