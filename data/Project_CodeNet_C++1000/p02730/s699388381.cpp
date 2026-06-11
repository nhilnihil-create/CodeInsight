#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  
  int n = s.size();
  int flag = 0;
  for(int i = 0; i < n/2; i++){
    if(s[i] != s[n-1-i]){
      flag = 1;
    }
  }
  
  for(int i = 0; i < ((n-1)/2)/2; i++){
    if(s[i] != s[(n-1)/2-1-i]){
      flag = 1;
    }
  }
  
  for(int i = (n+3)/2-1; i < n; i++){
    if(s[i] != s[n-i-1]){
      flag = 1;
    }
  }
  
  if(flag == 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
    
}