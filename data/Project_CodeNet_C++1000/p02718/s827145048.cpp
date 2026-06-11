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
      


      int n;
      cin>>n;
      int m;
      cin>>m;
      vector<int> a(n);
      lld s=0;
      for (int i = 0;i<n;i++){cin>>a[i]; s +=a[i];}
        sort(a.rbegin(), a.rend());
      // cout<<s<<endl;
      s = s/(4*m);
      // cout<<s<<endl;
      bool ok = true;
      for (int i = 0;i<m;i++) if (a[i]<s) ok =false;
      if (ok)
        cout<<"Yes\n";
      else
        cout<<"No\n";
}
  