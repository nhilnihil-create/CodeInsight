#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  
  int num=0;
  int n = s.size();
  for(int i=0; i<n; i=i+2){
  if(s[i]!='L'){
  num++;
  }
  }
   for(int j=1; j<n; j=j+2){
     if(s[j]!='R'){
       num++;
     }
  }
  
  if(num==n){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
