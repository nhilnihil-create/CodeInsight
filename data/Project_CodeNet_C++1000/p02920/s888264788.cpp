#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define prt(x) cout << (x)
#define prtl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>b; i--)
#define mp(a, b) make_pair(a, b)
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
using P = pair<long long int, long long int>;
using Map = map<long long int, long long int>;

const ll M = 1000000007;
 
vector<ll> fac(300001); //n!(mod M)
vector<ll> ifac(300001); //k!^{M-2} (mod M)
//a,bの範囲的にこれだけ配列を用意していけば十分

ll mpow(ll x, ll n){ //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % M;
        x = x*x % M;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % M;
    return tmp * fac[a] % M;
}

int main(){
    fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i<300000; i++){
        fac[i+1] = fac[i]*(i+1) % M; // n!(mod M)
        ifac[i+1] = ifac[i]*mpow(i+1, M-2) % M; // k!^{M-2} (mod M) ←累乗にmpowを採用
    }
    ll N; cin >> N;
    vll S(pow(2, N));
    Map n;
    rep(i, 0, pow(2,N)){
        cin >> S[i];
        if(n.find(S[i]) == n.end()){
            n[S[i]] = 1;
        }else{n[S[i]]++;}
    }
    sort(S.begin(),S.end(),greater<ll>());
    vll lis(0);
    ll m = S[0]; lis.emplace_back(m);
    rep(i, 1, pow(2,N)){
        if(S[i] != m){m = S[i]; lis.emplace_back(m);}
    }
    ll g = 0;
    for(auto x: lis){
        g = max(g, n[x]);
    }
    vll com(0);
    ll a = 0;
    rep(i, 0, N+1){
        a += comb(N, i);
        com.emplace_back(a);
    }
    ll c = 0;
    bool t = true;
    rep(i, 0, N+1){
        ll h = lis[i];
        rep(j, c, pow(2,N)){
            if(S[j] >= h){
                c++;
            }else{
                break;
            }
        }
        if(c > com[i]){
            t = false;
        }
    }
    if(g > pow(2, N-1)){t = false;}
    if(t){prt("Yes");}
    else{prt("No");}
}