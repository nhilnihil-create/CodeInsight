#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long 
int p[1000001];
int mod = 100000007;
int main() {
  int n;
  cin >> n;
  int a[n+1] = {};

  for(int i = 1;i<n+1;i++){
    cin >> a[i]; 
  }
  int b[n+1] = {};
  
  int tmp = 0;
  int res = 0;
  for(int i = n ;i> 0;i--){
    tmp = 0;
    
    for(int j = 2;j<=n;j++){
      if(i*j <= n){
        if(b[i*j] == 1){ tmp++; }
      }else{break;}
    }
    
    if((a[i] == 0 && tmp%2 ==1) || (a[i] == 1 && tmp%2 == 0)){
      b[i] = 1;
      //cout << a[i] << tmp<<  << endl;
      res++ ;
    }
  }
  cout << res << endl; 
  for(int i = 1; i<n+1;i++){
    if(b[i] == 1){
      cout << i << " " ;
    }
  }
}