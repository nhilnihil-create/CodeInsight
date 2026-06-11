#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"

ll power(ll a, ll b){
  ll res = 1;

  while (b > 0){
    if (b%2) res *= a;
    a *= a;
    b /= 2;
  } 

  return res;
}

 
int main ()
{
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #define int ll
  
  int x;
  cin >> x;

  map <int, int> hello;
  
  for (int i=0; true; i++){
    int now = power(i, 5);
    if (now > 2e18) break;
    hello[now] = i;
    hello[-now] = -i;
  }
  // int num1, num2;
  int ans1, ans2;

  for (auto it = hello.begin(); it != hello.end(); it++){
    int now = it->first;
    int need = x + now;
    if (hello.count(need)){
      ans1 = hello[need];
      ans2 = it->second;
      break;
    }
  }

  cout << ans1 << " " << ans2 << endl;
  
  
  return 0;
  
}
