 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
 const int INF = 2147483647;
 const ll MOD = 1000000007;
 // const ll INF = 1000000000000000000LL;
 
 ll modpow(ll x, ll n) {
     ll res = 1;
     while (n > 0) {
         if (n & 1) {  // nが奇数のとき
             res *= x;
             res %= MOD;
         }
         x *= x;
         x %= MOD;
         n >>= 1;
     }
     return res;
 }

 int main() {
   ll n,a,b;
   cin >> n >> a >> b;
   ll all = modpow(2,n);
   //aの分子
   ll a_u = 1;
   for(int i=1;i<=a;i++){
     a_u *= i;
     a_u %= MOD;
   }
   ll a_d = 1;
   //aの分母
   for(int i=0;i<a;i++){
     a_d *= n-i;
     a_d %= MOD;
   }
  //bの分子
   ll b_u = 1;
   for(int i=1;i<=b;i++){
     b_u *= i;
     b_u %= MOD;
   }
   ll b_d = 1;
   //bの分母
   for(int i=0;i<b;i++){
     b_d *= n-i;
     b_d %= MOD;
   }
   ll com_a,com_b;
   com_a = a_d * modpow(a_u,MOD-2) % MOD;
   com_b = b_d * modpow(b_u,MOD-2) % MOD;
   ll ans = all - com_a - com_b - 1;
   while(ans<0){
    ans+=MOD;
   }
  cout << ans << endl;
 }