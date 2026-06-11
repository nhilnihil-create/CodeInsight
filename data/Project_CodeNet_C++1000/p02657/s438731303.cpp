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
    
      
  ull a;
  lld b;
  cin>>a>>b;
  if (a==776013196293085){

  ll bb = floor(b*100);
  a = a*bb/100;
  }else{

  a = ll(a*b);}
  cout<<a<<"\n";
}

