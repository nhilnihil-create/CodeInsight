#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const double PI = acos(-1);  

int main(){
  string s; cin >> s;
  ll k; cin >> k;
  int n=s.size();

  int bc=0, fc=0;
  for(int i=n-1; 0<=i; i--){
    if(s[0]!=s[i]) break;
    bc += 1;
  }
  if(0<bc && bc<n){
    for(int i=0; i<n; i++){
      if(s[0]!=s[i]) break;
      fc += 1;
    }
  }
  
  ll cnt=1, sum=0;
  for(int i=fc; i<n-bc-1; i++){
    if(s[i]==s[i+1]){
      cnt += 1; 
      if(i<n-bc-2) continue;
    }
    sum += cnt/2; cnt=1;
  }
  if(bc!=n){
    sum = sum*k+(fc+bc)/2*(k-1)+fc/2+bc/2;
  }else sum = bc*k/2;
  cout << sum<< endl;
}
