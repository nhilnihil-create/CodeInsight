#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll popcount(ll n){
  if(n == 0) return 0;
  else return 1 + popcount(n & (n-1));
}

ll f(ll n){
 ll times = 0;
  
  while(n){
    n %= popcount(n);
    times++;
  }
  
  return times;
}

ll toggleBit(ll n, ll k){
  return (n ^ (1 << (k-1)));
}

ll binaryToDecimal(string x) 
{ 
    string num = x; 
    ll dec_value = 0; 
  
    ll base = 1; 
  
    ll len = num.length(); 
    for (ll i = len - 1; i >= 0; i--) { 
        if (num[i] == '1') 
            dec_value += base; 
        base = base * 2; 
    } 
  
    return dec_value; 
} 

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int k;
  cin >> k;
  
  if(k%2 == 0 || k%5 == 0){
    cout << "-1";
    return 0;
  }
  
  else{
    ll s = 0;
    int i = 1;
    while(i <= (1e7)){
	  s = (s*10 + 7)%k;
      if(!s){
        cout << i;
        return 0;
      }
      i++;
    }
  }
  
  cout << "-1";
  
  return 0;
}

