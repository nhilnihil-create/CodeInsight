#include<cmath>
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
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
#define sz(x) int(x.sise())
#define mod 1000000007
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
ll N,M;

ll extgcd(ll a, ll b, ll &x, ll &y){
    if(a < b) swap(a, b);
    ll d = a;
    if(b != 0){
        d = extgcd(b, a%b, y, x);
        y -= (a/b) * x;
    }else{
        x=1;
        y=0;
    }
    return d;
}
 
int main(){
    cin>>N>>M;
    ll x, y;
    vec a(N);
    rep(i,N) cin>>a[i], a[i] /= 2;
    ll lcm = a[0];
    reps(i,1,N) {
        ll temp = extgcd(lcm, a[i], x, y);
        lcm = lcm * a[i] / temp;
        if(lcm > M){
            cout<<0<<endl;
            return 0;
        }
    }
    int rest = (lcm / a[0])%2;
    reps(i, 1, N){
        if(rest != (lcm / a[i])%2){
            cout<<0<<endl;
            return 0;
        }
    }
    cout<<1 + (M - lcm) / (lcm * 2)<<endl;
}