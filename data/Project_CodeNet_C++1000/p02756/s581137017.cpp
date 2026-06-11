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

void solve(){

  string s;
  cin>>s;
  int q;
  cin>>q;
  int rev = 0;
  string beg = "", en = "";
  while(q--){
    int t;
    cin>>t;
    if (t==1){
      rev++;
      swap(beg, en);
      // reverse(beg.begin(), beg.end());
      // reverse(en.begin(), en.end());
    }else{
      int f;
      char c;
      cin>>f>>c;
      if (f==1){
        if (rev%2==0)
        beg = c+beg;
        else
        beg = beg+c;
      }else{
        if (rev%2==0)
        en = en+c;
        else
        en = c+en;
      }
    }
  }
  if (rev%2==1){
    reverse(s.begin(), s.end());
    reverse(beg.begin(), beg.end());
      reverse(en.begin(), en.end());
  }
cout<< beg+s+en<<"\n";
}
 
  int main()
  {
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      // ifstream cin("input.txt");

    solve();

}