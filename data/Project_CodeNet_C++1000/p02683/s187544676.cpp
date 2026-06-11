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
  lld PI = 3.141592653;

// const int N = 2e5 + 5;

// int a[N];
// int n,k;
  


  int main()
  {
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     
      int n,m,x;
      cin>>n>>m>>x;
      int a[n][m];
      int c[n];
      for (int i = 0;i<n;i++){
        cin>>c[i];
        for (int j = 0;j<m;j++){
          cin>>a[i][j];
        }
      }
      ll ans = INF;
      for (int mask = 0;mask<(1<<n);mask++){
        vector<int> skill(m);
        ll cost = 0;
        for (int p = 0;p<n;p++){
          if ((1<<p)&mask){
            cost+=c[p];
            for (int i = 0;i<m;i++){
              skill[i]+= a[p][i];
            }
          }
        }
        bool ok = true;
        for (int i = 0;i<m;i++) if (skill[i]<x) ok = false;
        if (ok) ans = min(ans, cost);
      }
      if (ans==INF){
        cout<<"-1\n";
      }else{
        cout<<ans<<"\n";
      }
   
}
  