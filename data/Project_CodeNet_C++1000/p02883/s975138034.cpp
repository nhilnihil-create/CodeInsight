#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long 

int main() {
  ll n,k;
  
  cin >> n >> k;
    
  vector<int> a(n);
  vector<int> f(n);
  
  for(int i = 0;i<n;i++){
    cin >> a[i];
  }
  for(int i = 0;i<n;i++){
    cin >> f[i];
  }
  
  sort(a.begin(), a.end(),greater<int>());
  sort(f.begin(), f.end());
  ll mn = 0;
  ll mx = 1000000000000;
  //ll mx = 4;
  ll md;
  int flg = 0;
  int i;
  ll tmp;
  ll sh;
  while(mn != mx){
    
    tmp = k;
    md = (mn+mx)/2;
    //cout << mn << " " << md << " " << mx << endl;
    flg = 0;
    i = 0;
    while(i<n){
      sh =  md/f[i];
      if(a[i] > sh){
        tmp -= (a[i] -sh);
      }
      //cout << "a" << f[i] << " " << a[i] << " " << sh << " "<< tmp << endl;
      if(tmp<0){
        flg = 1;
        break;
      }
      i++;
    }
    
    if(flg == 0){
      mx = md; 
    }else{
      mn = md+1;
    }
  
  }
  cout << mx;
  //cout << sum;
}