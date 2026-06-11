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

//-----------------------------------------
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::chrono::system_clock::time_point start,end;
    start = std::chrono::system_clock::now();

    string s, t;
    cin >> s >> t;
    ll n = SZ(s);
    ll m = SZ(t);
    ll ans = 0 ;
    vector<ll> num ;
    vector<vector<ll>> pos(26,vector<ll>());
    REP(i,n){
        ll j = s[i] - 'a';
        pos[j].PB(i) ;
    }
    ll tmp = -1 ;
    REP(i,m){
        ll j = t[i] - 'a' ;
        if(pos[j].empty()){
            cout << -1 <<endl;
            return 0;
        }
        auto itr = LB(ALL(pos[j]),tmp) ;
        if(itr==pos[j].end()){
            num.PB(pos[j][0]+1) ;
            tmp = pos[j][0]+1 ;
        }
        else{
            ll k = itr - pos[j].begin() ;
            num.PB(pos[j][k]+1) ;
            tmp = pos[j][k]+1 ;
        }
    }
    ll tt = 0 ;

    /*

    REP(i,SZ(num)-1){
        cout << num[i] <<endl;
    }

    */

    REP(i,SZ(num)-1){
        if(num[i]>=num[i+1]){
            tt++ ;
        }
    }

    ans = tt*n + num[SZ(num)-1] ;

    cout << ans <<endl;






    end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast< std::chrono::milliseconds >(end - start).count();
    //std::cout << elapsed <<"ms"<< std::endl;

    

    return 0;
}

