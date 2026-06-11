#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  string s;
  cin >> s;

  ll k;
  cin >> k;

  int n = s.size();
  
  int a=0;
  rep(i,n-1){
    if(s.at(i)==s.at(i+1)){a++; i++;}
  }
  int fi=1, la=1;
  rep(i,n-1){
    if(s.at(i)==s.at(i+1)) fi++;
    else break;
  }
  rep(i,n-1){
    if(s.at(n-1-i)==s.at(n-2-i)) la++;
    else break;
  }

  if(fi==n){
    ll p = n*k/2;
    cout << p;
    return 0;
  }
  
  int b=0;
  if(s.at(0)==s.at(n-1)&&fi%2==1&&la%2==1) b=1;
  

  ll ans = k*a + (k-1)*b;
  cout << ans;
}
