#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main(){
  ll n,k,ans =-10e9;
  cin >> n >> k;
  vector<ll>p(n),c(n);
  for(int i=0; i<n; i++){
    cin >> p[i];
    p[i]--;
  }
  for(int i=0; i<n; i++) cin >> c[i];
  
  for(ll i=0; i<n; i++){
    ll count=0,sum=0,x = i;
    vector<ll>m(n+1,-10e9);
    do{
      count++;
      x = p[x];
      sum += c[x];
      m[count] = max(m[count],sum);
    }while(x != i);
    
    ll roop,all = -10e9;
    roop = k/count;
    if(roop  == 0){
      for(int j=1; j<=k%count; j++){
        all = max(all,m[j]);
      }
    }else{
      for(int j=1; j<=k%count+count; j++){
         if(j>count){
          all = max(all,m[count]+m[j-count]);;
        }else{
          all = max(all,m[j]);
        }
      }
    }
    if(roop>0 && m[count] > 0)all += m[count]*(roop-1);
    ans = max(ans,all);
  }
  
  
  
  cout << ans << endl;
  
}