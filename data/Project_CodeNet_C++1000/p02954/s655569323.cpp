#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main(){
  string s;
  cin >> s;
  vector<ll> c(s.size(), 0);
  
  int i, j;
  i = 0; j = 1;
  while(true){
    if(s[j]=='L'){
      if((j-i)%2==0){
        c[j-1] += (j-i)/2;
        c[j] += (j-i)/2;
      }else{
        c[j-1] += ((j-i)/2)+1;
        c[j] += (j-i)/2;
      }
      i = j+1;
    }
    j++;
    if((i+1)>=s.size()) break;
  }
  
  i = s.size()-1; j = i-1;;
  while(true){
    if(s[j]=='R'){
      if((i-j)%2==0){
        c[j+1] += (i-j)/2;
        c[j] += (i-j)/2;
      }else{
        c[j+1] += ((i-j)/2)+1;
        c[j] += (i-j)/2;
      }
      i = j-1;
    }
    j--;
    if(i<=0) break;
  }
  
  
  
  
  for(int i=0; i<s.size(); i++) cout << c[i] << " ";
  cout << endl;
  
  return 0;
}