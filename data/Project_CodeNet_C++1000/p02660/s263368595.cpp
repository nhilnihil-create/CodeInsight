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
    
      
  ll n;
  cin>>n;
  ll nn = n;
  ll ans = 0;
  set<ll> have;
  for (ll i = 2;i*i<=n;i++){
    ll v = i;
    
    // cout<<nn<<" "<<v<<endl;
    if (!have.count(v))
    while (nn%v==0){
      have.insert(v);
      ans++;
      nn/=v;
       v*=i;
    //    cout<<nn<<" "<<v<<endl;
    // cout<<ans<<endl;
    }
    while (nn%i==0) nn/=i;
    
  }
  // cout<<nn<<endl;
  // cout<<ans<<endl;
  bool ok = true;
  for (ll i = 2;i*i<=nn;i++){
    if (nn%i==0) ok = false;
  }
  // cout<<ans<<endl;

if (ok && !have.count(nn) && nn!=1) ans++;
cout<<ans<<"\n"; 
}
