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
  
  int n;
  cin >> n;

  map <int, int> mp;
 
  int ans = 0;
  vector <int> numbers(n);
  for (int i=0; i<n; i++){
    
    cin >> numbers[i];
    mp[numbers[i]+i]++;
  }

  for (int j=1; j<n; j++){
    ans += mp[j - numbers[j]];
  }

  cout << ans << endl;
  
  return 0;
  
}
