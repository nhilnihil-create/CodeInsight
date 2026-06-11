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

 ll n;
 cin>>n;
 ll zn = 5;
 ll num = 0;
 if (n%2==1){
  cout<<"0\n";
  return 0;
 }
 while (n/zn>=1){
  num+=(n/zn+n%2)/2;
  
  zn*=5;
  
 }

 cout<<num<<"\n";


}