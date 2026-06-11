#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
  
  ll n,k;
  cin >> n >> k;
  
  vector<ll>a(n);
  for(int i=0; i<n; i++){
   cin >> a[i]; 
  }
  
  vector<ll>front(n),back(n);
  for(int i=0; i<n; i++){
   for(int j=0; j<n; j++){
     if(i<j && a[i]>a[j]) back[i]++;//後ろよりでかい通り
     else if(i>j && a[i]>a[j]) front[i]++;//前よりでかい通り
   }
  }
  
  ll ans=0,f=0,b=0;
  for(int i=0; i<n; i++){
    b=k*(k+1)/2%1000000007;
    f=k*(k-1)/2%1000000007;
     
    ans+=f*front[i];
    ans%=1000000007;
    ans+=b*back[i];
    ans%=1000000007;
  }
  
  cout << ans << endl;
  
  return 0;
  
}
