//g++ main.cpp -I /usr/local/include/ac-library
#include<cmath>
//#include <atcoder/all>
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
//using namespace atcoder;
stack<int> st;
queue<int> qu;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
#define ALL(a) a.begin(), a.end()
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair
#define pb push_back
#define sz(x) (int)(x).size()
#define mod 1000000007
//#define mint=modint1000000007
#define reps(i,s,n) for(int i = s; i < n; i++)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
deque<int> deq;
#define fi first
#define se second
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
typedef pair<int, int> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    ll D=0;
    ll S=0;
    int m;
    cin >> m;
    rep(i,m){
        ll d,c;
        cin >> d>> c;
        D+=c;
        S+=d*c;
    }
    ll ans=D-1+(S-1)/9;
    cout<<ans<<endl;
    return 0;
}