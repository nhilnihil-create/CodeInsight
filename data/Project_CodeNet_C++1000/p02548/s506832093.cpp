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
#include <fstream>
#include <climits>
 
  using namespace std;
   
 
//abcdefghijklmnopqrstuvwxyz
//ABCDEFGHIJKLMNOPQRSTUVWXYZ

  typedef long long ll;
  typedef long double lld;
  typedef unsigned long long ull;
  int INF = INT_MAX;
  // ll mod = 998244353;
  // lld PI = 3.141592653;







  int main()
  {
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
      int n;
      cin>>n;
      ll ans = 0;
      for (int a = 1; a<=n;a++){
        ans+= (n-1)/a;
      }
      cout<<ans<<"\n";

}