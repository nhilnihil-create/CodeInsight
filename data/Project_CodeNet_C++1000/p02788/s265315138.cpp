#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1001001001001001001;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    ll n, d, a; cin >> n >> d >> a;
    vector<pll> monster(n);
    rep(i, n){
        ll x, h; cin >> x >> h;
        monster[i] = {x, h};
    }
    sort(all(monster));

    vector<ll> right, S(n+1);
    rep(i, n){
        ll X = monster[i].first, H = monster[i].second;
        ll r = X + d*2;//爆風の東端
        if(i==0){
            right.push_back(r);
            S[i+1] = S[i] + (H+a-1)/a;
        }else{
            int index = lower_bound(all(right), X) - right.begin(); //爆風が届く最初の爆破
            //cout << "index:" << index;
            int num = right.size() - index; //num個の爆発に巻き込まれている
            //cout << " num:" << num;
            ll b_dam = (S[i] - S[i - num]) * a;//他の爆発に巻き込まれて受けたダメージ
            //cout << " b_dam:" << b_dam;
            H -= b_dam;
            ll cnt = H>0 ? (H+a-1)/a : 0;
            S[i+1] = S[i] + cnt;
            right.push_back(r);
        }
        //cout << ln;
    }
    cout << S.back() << ln;
    //for(ll tmp: S)cout << tmp << " "; cout << ln;
}