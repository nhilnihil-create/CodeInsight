#include <bits/stdc++.h>
#include <limits>
#include <math.h>
#include <cmath>
#include <cctype>
#include <cstdio>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll> ;
using vs = vector<string>;
using vb = vector<bool>;
using vll = vector<long long>;
using vvll = vector<vector<long long >>;
#define PI  3.1415926535
#define rep(i, k, n) for(ll i = k; i < n; i++)

int main(){
  	ll MOD = 1000000007;
	ll n; cin >> n;
    vll a(n);
    rep(i, 0, n){cin >> a[i];}
    
    vll count1(100, 0);
    vll sum(100);
    
    rep(i, 0, n){
    	vll shinsu (0);
        while(a[i] > 1){
        	shinsu.emplace_back(a[i]%2);
            a[i] /= 2;
        }
      	if(a[i] != 0){shinsu.emplace_back(1);}
      	else{shinsu.emplace_back(0);}
      
      //for(auto x:shinsu){cout << x;}
      //cout << endl;
      	
      rep(j, 0, shinsu.size()){if(shinsu[j] == 1){count1[j]++;}}
    }
  //cout << count1[0] << count1[1] << count1[2] << count1[3] << endl;
  ll ans = 0;
  rep(i, 0, 100){
    sum[i] = count1[i] * (n - count1[i]);
    ll res = pow(2, i);
    ans += ((sum[i] % MOD) * (res % MOD)) % MOD;
    ans %= MOD;
  }
  
  cout << ans << endl;
}
  
  
    
    