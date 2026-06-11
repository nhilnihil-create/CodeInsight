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
     
   int n,m;
   cin>>n>>m;
   vector<int> h(n+1);
   for (int i =1;i<=n;i++) cin>>h[i];
    vector<int> from_me[n+1];
    for (int i = 0;i<m;i++){
      int a,b;
      cin>>a>>b;
      from_me[a].push_back(b);
      from_me[b].push_back(a);
    }
    // cout<<"--\n";
    int ans = 0;
    for (int i = 1;i<=n;i++){
      bool ok = true;
      
      for (int j = 0;j<from_me[i].size();j++){
        if (h[from_me[i][j]]>=h[i]) {ok =false; }
      }
      if (ok) {ans++; }
    }
   cout<<ans<<"\n";
}
  