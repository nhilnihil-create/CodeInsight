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
//   ll INF = INT_MAX;
  // ll mod = 998244353;
  lld PI = 3.141592653;

// const int N = 2e5 + 5;

// int a[N];
// int n,k;
  



 






  int main()
  {
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     

   int a,b,h,m;
   cin>>a>>b>>h>>m;
    lld a1 = lld(m)/60 * 2 * PI;
    lld a2 = ((lld)h*60+m)/(12*60) * 2 * PI;
    a1 = abs(a1-a2);
    lld ans = sqrt(a*a+b*b-2*a*b*cos(a1));
    cout<<setprecision(20)<<ans<<endl;
  

}
  