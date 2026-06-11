#include <bits/stdc++.h>
using namespace std;


#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

ll mod = 1e9 + 7ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll inf = 1ll << 60;

string s;

vector<ll> three_pow(int n){
    vector<ll> res(n);
    res.at(0) = 1;
    rp(i, 1, n)  res.at(i) = (res.at(i-1) * 3) % mod;
    return res;
}

vector<ll> two_pow(int n){
    vector<ll> res(n);
    res.at(0) = 1;
    rp(i, 1, n)  res.at(i) = (res.at(i-1) * 2) % mod;
    return res;
}

int main() {
    cin >> s;
    int n = s.size();
    vector<ll> three(n+10);
    three = three_pow(n+10);
    vector<ll> two(n+10);
    two = two_pow(n+10);

    ll res = 0;
    int count = 0;
    rp(i, 0, n){
        if(s[i] == '1'){
            res += (three.at(n - i - 1) * two.at(count))%mod;
            res %= mod;
            count ++;
        }
    }
    res += two.at(count);
    res %= mod;
    printf("%lld\n", res);
    return 0;
}

