#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> divisor(ll n) {
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

int main(){
    
    ll N; cin >> N;
    vector<ll> result{};
    result = divisor(N);
    int len = result.size()/2;
    if(result.size() %2 ==0) cout << result[len] - 1 + result[len-1] -1 << endl;
    else cout << result[len] - 1 + result[len] -1 << endl;
} 