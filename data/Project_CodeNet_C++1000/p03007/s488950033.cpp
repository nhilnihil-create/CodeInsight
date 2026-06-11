#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll n,count=0;
  cin >> n;
  vector<ll>a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  sort(a.begin(),a.end());
  
  if(n==2){
    cout << a[1]-a[0] << endl;
    cout << a[1] << " " << a[0] << endl;
    return 0;
  }
  
  
  vector<ll>x(n-1),y(n-1);
  queue<ll>plus;
  queue<ll>minus;
  for(int i=0; i<n; i++){
    if(a[i]>=0)plus.push(a[i]);
    else minus.push(a[i]);
  }
    
  if(plus.size()==0){
    for(int i=0; i<n-2; i++){
      ll p = minus.front();
      minus.pop();
      minus.push(p);
    }
    ll minus1=minus.front();
    minus.pop();
    ll minus2=minus.front();
    minus.pop();
    plus.push(minus2-minus1);
    x[count]=minus2;
    y[count]=minus1;
    count++;
  }
  
  if(minus.size()==0){
    ll plus1=plus.front();
    plus.pop();
    ll plus2=plus.front();
    plus.pop();
    minus.push(plus1-plus2);
    x[count]=plus1;
    y[count]=plus2;
    count++;
  }
  
  while(plus.size()>1){
    ll P = plus.front();
    ll M = minus.front();
    plus.pop();
    minus.pop();
    minus.push(M-P);
    x[count]=M;
    y[count]=P;
    count++;
  }
  
  while(minus.size()>0){
    ll P = plus.front();
    ll M = minus.front();
    plus.pop();
    minus.pop();
    plus.push(P-M);
    x[count]=P;
    y[count]=M;
    count++;
  }
  
  ll ans = plus.front();
  cout << ans << endl;
  
  for(int i=0; i<n-1; i++) cout << x[i] << " " <<  y[i] << endl;
  
  return 0;
  
}