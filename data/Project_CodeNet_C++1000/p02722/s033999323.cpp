#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
#include<stack>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;

vector<ll> res;

void enum_divisors(long long N) {
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N / i != i) res.push_back(N / i);
        }
    }
    // 小さい順に並べ替える
    sort(res.begin(), res.end());
}

vector<ll> resi;

void enum_divisorsi(long long N) {
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            resi.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N / i != i) resi.push_back(N / i);
        }
    }
    // 小さい順に並べ替える
    sort(resi.begin(), resi.end());
}

int main() {
    ll n;
    cin >> n;
    enum_divisors(n);
    enum_divisorsi(n - 1);
    ll ans = 0;
    ans += (ll)sz(resi);
    ans--;

    rep(i, sz(res)) {
        ll ri = res[i];
        ll cnt = res[i];
        if(ri==1) continue;
        bool flag = false;
        while (cnt <= n && flag == false&&n%cnt==0) {
            if ((n / cnt) % ri == 1) flag = true;
            cnt *= ri;
        }
        if (flag) ans++;
    }
    cout << ans << endl;
}