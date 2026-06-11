    #include<iostream>
    #include<stdio.h>
    //#include <bits/stdc++.h>
    #include<vector>
    #include<float.h>
    #include<iomanip>
    #include<algorithm>
    #include<string>
    #include<cstring>
    #include<math.h>
    #include<cmath>
    #include<sstream>
    #include<set>
    #include<map>
    #include<queue>
    #include<cassert>
    #include<cmath>
    #include<cstdint>
    #include<numeric>
    #include<array>
     
    #define INF 1e9
    #define rep(i,n)for(int i=0;(i)<(int)(n);i++)
    #define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
    #define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
    #define vec(type,n) vector<type>(n)
    #define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
    #define ALL(a)  (a).begin(),(a).end()
    #define chmin(a, b) a = min(a, b)
    #define chmax(a, b) a = max(a, b)
    #define Vl vector<ll>
     
    using namespace std;
    using ll = long long;
    using Graph = vector<vector<int>>;
    using P = pair<ll, ll>;
     
const ll MOD = 1e9 + 7;
const ll ZER = 0;

ll mpow(ll x, ll n){
    if(n < 0)return 0;
    ll ans = 1;
    while(n != 0){
        if(n & 1)ans = ans * x % MOD;
        x = x * x % MOD;
        n = n >> 1;
    }
    return ans;
}

int main(){
   ll n;
   cin >> n;
   ll res = mpow(10, n) - mpow(9, n) - mpow(9, n) + mpow(8, n);
   res %= MOD;
   if(res < 0)res += MOD;
   cout << res << endl;
}
