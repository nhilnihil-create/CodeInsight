 #include <iostream>
  #include <complex>
  #include <vector>
  #include <string>
  #include <algorithm>
  #include <cstdio>
  #include <numeric>
  #include <cstring>
  #include <ctime>
  #include <cstdlib>
  #include <set>
  #include <map>
  #include <unordered_map>
  #include <unordered_set>
  #include <list>
  #include <cmath>
  #include <bitset>
  #include <cassert>
  #include <queue>
  #include <stack>
  #include <deque>
 #include <iomanip>
 
  using namespace std;
   

//abcdefghijklmnopqrstuvwxyz
//ABCDEFGHIJKLMNOPQRSTUVWXYZ
  typedef long long ll;
  typedef long double lld;
//   typedef string str;
//   typedef unsigned long long ull;
  ll INF = INT_MAX;
  ll mod = 1000000007;
  // lld PI = 3.141592653;

// const int N = 2e5 + 5;

// int a[N];
// int n,k;
  
 
ll power(ll a, ll b){
  if (a==0) return 0;
 ll result = 1;
 while (b>0){
   if (b%2==1) result = (result*a)%mod;
   a = (a*a)%mod;
   b/=2;
 }
 return result;
}

  int main()
  {
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int n,k;
      cin>>n>>k;
      ll cnt[k+1];
      cnt[k] = 1;
      ll ans = k;
      for (int a = k-1;a>=1; a--){
        ll zn = k/a;
        cnt[a] = power(zn, n);
        for (ll j = a*2; j<=k;j+=a){
          cnt[a] = (cnt[a]-cnt[j]+mod)%mod;
        }
        ans = (ans+cnt[a]*a)%mod;
      }
      cout<<ans<<"\n";
}
  