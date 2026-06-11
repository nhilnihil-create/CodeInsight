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
  typedef string str;
  typedef unsigned long long ull;
  ll INF = INT_MAX;
  // ll mod = 998244353;
  lld PI = 3.141592653;
 
// const int N = 2e5 + 5;
 
// int a[N];
// int n,k;
 
 
 
// void solve(){
 
// string s;
// cin>>s;
 
 
// }
 
 
 
  int main()
  {
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
      
   int n;
   cin>>n;
   vector<int> a(n);
   // multiset<int> b;
   vector<int> b(1000005);
   for (int i = 0;i<n;i++) {cin>>a[i]; b[a[i]]++;}
    sort(a.begin(), a.end());
 
  vector<bool> dp(a[n-1]+10, true);
  for (int i = 0;i<n;i++){
    int v = a[i];
    if (dp[v]){
      // if (v*v<=a[n-1]+2){
        for (int j = v*2; j<= a[n-1]+2;j+=v) {dp[j] = false; }
      // }
    }
  }
  int ans = 0;
 
  for (int i = 0;i<n;i++){
    if (dp[a[i]] && b[a[i]]==1) {ans++; }
  }
  // cout<<endl;
cout<<ans<<"\n";
 
}
 