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
  vector<int> a(n);
  vector<int> have(n+1);
  for (int i = 0;i<n;i++){
    cin >>a[i];
    if (i+1-a[i]>=2){
      have[i+1-a[i]]++;
    }
  }
  ll ans= 0;
  for (int i = 0;i<n;i++){
    if (i+1+a[i]<=n){
       ans+= have[i+1+a[i]];
    }
   if (i+1-a[i]>=2){
      have[i+1-a[i]]--;
   }
  
  }
  cout<<ans<<"\n";

}
  