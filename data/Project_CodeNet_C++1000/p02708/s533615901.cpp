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
  
 

  int main()
  {
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      
      int n,k;
      cin>>n;
      // n++;
      cin>>k;
      ll ans = 0;
      ll pis = 0;
      ll v_sum = 0;
      for (ll kk = 1;kk<=n+1;kk++){
        if (kk>=k) ans= (ans+ n*kk-v_sum+1)%mod;
         // cout<<v_sum<<endl;
       

        pis++;
         v_sum= (v_sum + 2*pis)%mod;
      }
      cout<<ans<<"\n";


}
  