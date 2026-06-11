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
      // ifstream cin("max_02.txt");

      
    ll n;
    cin>>n;
    set<ll> a;
    if (n==2){
      cout<<"1\n";
      return 0;
    }
    a.insert(2);
    a.insert(n-1);
    a.insert(n);
    for (ll i = 2; i*i<=n-1;i++){
      if ((n-1)%i==0) {a.insert(i); a.insert((n-1)/i);}

    }
    // cout<<a.size()<<endl;
 
    for (ll i = 3;i*i<=n;i++){
      ll nn = n;
      while (nn%i==0) nn/=i;
      nn%=i;
      if (nn==1){a.insert(i);}
    }
    cout<<a.size()<<"\n";

}
  