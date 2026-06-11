#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define int ll
using namespace std;
typedef long long ll;
signed main(){
  string s;
  int k;
  cin >> s >> k;
  
  int size = s.size();
  
  string check;
  rep(i,size) check += s[0];
  if(check == s){ cout << size*k/2 << endl; return 0; }
  
  int mae = 1, usiro = 1;
  if(s[0] == s[size-1]){
    int i = 1;
    while(s[0] == s[i]){
      mae++; i++; 
    }
    
    i = size -2;
    while(s[size-1] == s[i]){
      usiro++; i--;
    }
  }
  
  int ans = 0, temp = 1;
  rep(i,size-1){
    if(s[i] == s[i+1]) temp++;
    else{ ans += temp/2; temp = 1; }
  }
  ans += temp/2;
  //cout << ans << endl;
  ans *= k;
  //cout << ans << endl;
  if(mae != 1 || usiro != 1){
  ans = ans - (mae/2)*(k-1) -(usiro/2)*(k-1) + ((mae+usiro)/2)*(k-1);
  }
  //cout << mae << endl << usiro << endl;
  
  cout << ans << endl;
  return 0;
}