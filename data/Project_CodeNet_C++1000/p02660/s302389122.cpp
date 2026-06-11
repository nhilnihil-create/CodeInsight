#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

struct Sieve {
    int n;
    vector<int> f,primes;
    Sieve(int n = 1):n(n),f(n+1){
        f[0] = f[1] = -1;
        for(ll i = 2;i <= n;i++){
            if(f[i]) continue;
            primes.push_back(i);
            f[i] = i;
            for(ll j = i*i;j <= n;j += i) {
               if(!f[j]) f[j] = i;
            }
        }
    }

    bool isPrime(int x) {return f[x] == x;}
    vector<ll> factorList(ll x){
        vector<ll> res;
        for(int p : primes){
            while(x%p == 0){
                res.push_back(p);
                x /= p;
            }
        }
        if(x != 1) res.push_back(x);
        return res;
    }
    vector<pair<ll,int>> factor(ll x){
        vector<ll> fl = factorList(x);
        if(fl.size() == 0) return{};
        vector<pair<ll,int>> res(1,pair<ll,int>(fl[0],0));
        for(ll p : fl){
            if(res.back().first == p){
                res.back().second++;
            }else{
                res.emplace_back(p,1);
            }
        }
        return res;
    }
};



//     auto find_m = [&](int k){
//         for(int m = 1;m <= k;m++){
//             if(m*(m+1)/2 <= k && k < (m+1)*(m+2)/2 ) return m;
//         }
//         return -1;
//     };

//     ll n;
//     cin >> n;
//     vector<int> s(n);
//     set<ll> p;
//     while(true){
//         int rootn = sqrt(n) + 0.8;
//         bool flag = true;
//         for(int i = 2;i <= rootn;i++){
//             if(n%i == 0) {
//                 s[i] += 1;
//                 p.insert(i);
//                 n /= i;
//                 flag = false;
//                 break;
//             }
//         }
        
//         if(flag){
//             if(n > 1){
//                 s[n]++;
//                 p.insert(n);
//             }
//             break;
//         }
//     }

//     int ans = 0;
// for(auto itr = p.begin(); itr != p.end(); ++ itr){
//     ans += find_m(s[*itr]);
// }
// cout << ans << endl;

int main() {
  ll n;
  cin >> n;
  Sieve s(1000005);
  auto fs = s.factor(n);
  int ans = 0;
  for (auto p : fs) {
    int x = p.second;
    int b = 1;
    while (b <= x) {
      x -= b;
      b++;
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}