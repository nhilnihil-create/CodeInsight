//苦手 解説AC
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1000000007;
// const ll INF = 1000000000000000000LL;

//最大公約数
ll gcd(ll a,ll b){
    if(a<b) swap(a,b);
    bool have_mod =true;
    while(have_mod){
        ll mod = a % b;
        if(mod == 0 ) have_mod = false;
        a = b;
        b = mod;
    }
    return a;
}

// 素因数分解
// 素因数(1は含まない)の値と数をペア型のvectorに入れる
vector<pair<long long, long long> > prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

int main(){
    ll a,b;
    cin >> a >> b;
    ll g = gcd(a,b);
    auto pr = prime_factorize(g);
    cout << pr.size()+1 << endl;
	return 0;
}