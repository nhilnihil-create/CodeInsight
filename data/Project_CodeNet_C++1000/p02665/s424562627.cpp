#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0 ; i<(n) ; i++)
#define repr(i,n) for(int i=(n) ; i>=0 ; i--)
#define ALL(x) (x).begin(),(x).end()

using ll = long long;
using ull = unsigned long long;
 
const ll INF = 1LL<<60;
const int MINF = 1e9;
const int MOD = 1e9+7;

using vi = vector<int>;
using vii = vector<vi>;

template<typename T,typename U> bool chmax(T& a, U b) { if (a < b) { a = b; return true; } return false; }
template<typename T,typename U> bool chmin(T& a, U b) { if (a > b) { a = b; return true; } return false; }

template<typename T>
T GCD(T a,T b){ return b ? GCD(b,a%b) : a ;}
template<typename T>
T LCM(T a,T b){ return a*b / GCD(a,b) ;}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;cin >> n;
    vector<ll> a(n+1);
    rep(i,n+1)cin >> a[i];
    
    struct p{
        ll min;
        ll max;
    };

    if(n == 0){
        if(a[0] == 1)cout << 1 << endl;
        else cout << -1 << endl;
        return 0;
    }else if(a[0] == 1){
        cout << -1 << endl;
        return 0;
    }

    vector<p> sum;
    reverse(ALL(a));
    sum.push_back({a[0],a[0]});

    for(ll i=1;i<a.size();i++){
        ll min = (sum[i-1].min + 1)/2 + a[i];
        ll max = sum[i-1].max + a[i];
        sum.push_back({min,max});
    }

    reverse(ALL(sum));
    bool flag = false;
    for(ll i=sum[0].min;i<=sum[0].max;i++){
        if(i == 1){
            flag = true;
            break;
        }
        if(i >= 2)break;
    }
    if(!flag){
        cout << -1 << endl;
        return 0;
    }

    ll vertex = 1;
    ll ans = 1;
    reverse(ALL(a));
    for(ll i=1;i<=n;i++){
        ll tmp = vertex * 2;
        ans += min(tmp,sum[i].max);
        vertex = min(tmp,sum[i].max) - a[i];
    }
    
    cout << ans << endl;
    return 0;
}