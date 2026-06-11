#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL (1LL<<62) // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    ll n, m, v, p;
    cin >> n >> m >> v >> p;
    vi a(n);
    rep(i, n) cin >> a[i];
    // スコア上昇の上限はジャッジの人数
    sort(all(a), greater<ll>());
    map<ll, bool> isOK;
    ll pos = 0, sum = 0;
    for(; pos<n; pos++){
        // 上位p-1個は無条件にOK
        if(pos < p-1){
            isOK[a[pos]] = true;
            continue;
        }
        // 累積和の更新
        sum += a[pos];
        // 既にOKの数字なら飛ばす
        if(isOK[a[pos]]) continue;

        // 全員に投票させれば降順p番目の数字を超えられる場合
        if(a[pos]+m >= a[p-1]){
            // 先頭p-1個に投票した後、残りの票を自分を含む自分以下の数値に割り振ることが可能な場合
            if(pos <= n-v+p-1){
                isOK[a[pos]] = true;
                continue;
            }
            // 割り振り切れない場合、自分より大きい値にフラットになるように振れるか
            else{
                // 自分の最高値
                ll selfMax = a[pos]+m;
                // 自分を累積和に加えているので一旦取り除く
                sum -= a[pos];
                // 自分より大きな数の個数と残りの票
                ll num = pos - (p-1);
                ll leftVote = ((v-(p-1))-(n-pos))*m;
                // 自分の最高値を超えないように、自分より大きな数に割り振れるか
                if(num*selfMax-sum >= leftVote){
                    sum += a[pos];
                    isOK[a[pos]] = true;
                    continue;
                }
                else break;
            }
        }
        else break;
    }
    cout << pos << endl;
}