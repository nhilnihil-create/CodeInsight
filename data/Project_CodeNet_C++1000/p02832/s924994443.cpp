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
  typedef unsigned long long ull;
  // ll INF = INT_MAX;
  // ll mod = 1000000007;
  // lld PI = 3.141592653;
 
// const int N = 2e5 + 5;



  // void solve(){

  //   int n,m;

  //   cin>>n>>m;
  //   for (int tt=0;tt<m;tt++){
  //     int x,y;
  //     cin>>x>>y;
  //     adj[x].push_back()
  //   }
  // }


  int main()
  {
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      // ifstream cin("input.txt");


 int n;
 cin>>n;
 vector<int> a(n);
 for (int i = 0;i<n;i++) cin>>a[i];
  int i = 0;
int f = 1;
while(i<n){
  while (i<n && a[i]!=f) i++;
  if (i==n){
    if (f==1) f=n+2;
    cout<<n-(f-1)<<"\n";
    // cout<<f<<endl;
    return 0;
  }
  f++;
}


}