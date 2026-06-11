#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
const int INF = 1e6;

long long add(long long a, long long b) {
    long long res = a + b;
    if (res >= mod) res -= mod;
    return res;
}

long long sub(long long a, long long b) {
    long long res = a - b + mod;
    if (res >= mod) res -= mod;
    return res;
}

long long mul(long long a, long long b) {
    return (((a % mod) * (b % mod)) % mod);
}

long long potolok(long long a, long long b){   // округление вверх для целых
    return (a + b - 1) / b;
}


long long gcd(long long x, long long y){
    if(y == 0){
        return x;
    }
    if(x > y){
         return gcd(y, x % y);
    }
    else{
         return gcd(x, y % x);
    }
}

bool cmpr(int x, int y){            // сортировка по абсолютной величине
    if(abs(x) < abs(y)) return true;
    else{
        return false;
    }
}

bool comp(pair<int, int> x, pair<int, int> y){  // сортировка по первой компоненте
    if(x.first < y.first)return true;
    else if(x.first == y.first){
        if(x.second < y.second)return true;
        else return false;
    }
    else{
        return false;
    }
}

int cnt(string &s, string &p, int m, int n){
    if((m == 0 && n == 0) || n == 0){
        return 1;
    }
    if(m == 0){
        return 0;
    }
    if(s[m - 1] == p[n - 1]){
        return cnt(s, p, m - 1, n - 1) + cnt(s, p, m - 1, n);
    }
    else{
        return cnt(s, p, m - 1, n);
    }
}

int div(int n){
    int ans = 0;
    vector<int> used(n + 1, 0);
    for(int i = 1;i <= sqrt(n);i++){
        if(n % i == 0 && (!used[i] && !used[n / i])){
            if(i * i == n){
                ans++;
            }
            else{
                ans += 2;
            }
        }
    }
    return ans;
}

void solve(){
    long long n;
    cin >> n;
    vector<long long> primes = {2, 3, 5, 7, 11, 13};
    for (int i = 17; i <= n - 1; i += 2) {
    bool is_prime = true;
    for (int j = 0; primes[j] * primes[j] <= i; ++j) {
      if (i % primes[j] == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime)
      primes.emplace_back(i);
    }
    long long ans = 0;
    for(long long i = 1;i < n;i++){
        long long k = i;
        long long fac = 1;
        for(long long j = 0;primes[j] * primes[j] <= k;j++){
            if(j >= primes.size()){
                cout << " SYKA " << endl;
            }
            if(k % primes[j] == 0){
                long long cnt = 0;
                while(k % primes[j] == 0){
                    cnt++;
                    k /= primes[j];
                }
                fac *= (cnt + 1);
            }
        }
        if(k != 1){
            fac *= 2;
        }
        ans += fac;
    }
    cout << ans << endl;
}

int main(){
    int t = 1;
    while(t--){
        solve();
    }
 }
