#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> div(long long n) {
    vector<long long > res;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.emplace_back(i);
            if (i != n / i) res.emplace_back(n / i);
        }
    }
    return res;
}

int main() {

    long long n, k;
  
    cin >> n >> k;
  
    vector<long long> a(n);
  
    for(int i=0;i<n;i++){
      cin >> a[i];
    }

    vector<long long> divs = div(accumulate(a.begin(),a.end(), 0LL));

    long long ans = 0;
  
    for(auto & e : divs){
      
        vector<long long> mods(n);
        for(int i=0;i<n;i++) mods[i] = a[i] % e;
      
        sort(mods.begin(),mods.end());

        vector<long long> minus(n + 1);
        for(int i=0;i<n;i++) minus[i + 1] = minus[i] + mods[i];

        vector<long long> plus(n + 1);
        for(int i=n-1;i>=0;i--) plus[i] = plus[i + 1] + e - mods[i];

        for (long long i = 0; i <= n; ++i) {
            if (max(plus[i], minus[i]) <= k) ans = max(ans, e);
        }
    }
    cout << ans << endl;
   
}
