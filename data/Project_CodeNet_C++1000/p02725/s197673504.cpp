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
 
  using namespace std;
   
 
//abcdefghijklmnopqrstuvwxyz
//ABCDEFGHIJKLMNOPQRSTUVWXYZ

  typedef long long ll;
  typedef long double lld;
//   typedef unsigned long long ull;
  // ll INF = INT_MAX;
  // ll mod = 1000000007;
  // lld PI = 3.141592653;
 
// const int N = 2e5 + 5;


 
  int main()
  {
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      // ifstream cin("input.txt");

    int k,n;
    cin>>k>>n;
    vector<int> a(n);
    int start = 0;
    int dist_max = 0;
    for (int i = 0;i<n;i++) cin>>a[i];
    ll ans = 0;
    for (int i = 0;i<n;i++){
     if ((a[(i+1)%n]-a[i]+k)%k > dist_max){
      dist_max = (a[(i+1)%n]-a[i]+k)%k;
      start = (i+1)%n;
     }

    }
    // cout<<start<<endl;
    for (int i = start; i<start+n-1;i++){
      ans+= (a[(i+1)%n]-a[i%n]+k)%k;
    }
    cout<<ans<<"\n";

}