#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int  main(){
  string s;
  cin >> s;
  ll n = s.size() + 1;

  vector<ll> a(n, 0);

  for(ll i=0; i<n-1; ++i){
    if(s[i]=='<'){
      a[i+1] = max(a[i+1], a[i]+1);
    }
  }

  for(ll i=n; i>0; --i){
    if(s[i-1]=='>'){
      a[i-1] = max(a[i-1], a[i]+1);
    }
  }

  ll sum = 0;

  for(ll i=0; i<a.size(); ++i){
    sum+= a[i];
  }

  cout << sum;
  return 0;
}