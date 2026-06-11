#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

//　最大値注意!!
const int MAX_N = 100001;

//　選べる仕事の中で、終了時間が最も小さいものを選ぶことを繰り返す.

int main(){
    ll n, time = 0;
    cin >> n;
    vector<ll> x(n), l(n);
    vector<ll> s(n), t(n);
    rep(i, n) cin >> x[i] >> l[i];
    rep(i, n){
        s.at(i) = x.at(i) - l.at(i);
        t.at(i) = x.at(i) + l.at(i);
    }
    pair<ll, ll> itv[n];

    // pairは辞書順で比較される。
    //　終了時間が早い順にしたいため、Tをfirstに、Sをsecondに入れる。
    rep(i, n) {
        itv[i].first = t[i];
        itv[i].second = s[i];
    }
    sort(itv, itv+n);

    // timeは最後に選んだ仕事の終了時間
    ll answer = 0;
    time = -1000000000;
    rep(i, n) {
        if(time <= itv[i].second) {
            answer++;
            time = itv[i].first;
        }
    }

    cout << answer << endl;
}