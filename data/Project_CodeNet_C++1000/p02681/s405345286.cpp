#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s,t;
  cin >> s >> t;
  
  int flag = 0;
  if(s.size() + 1 != t.size()){
    flag = 1;
  }

  int n = s.size();
  for(int i = 0; i < n; i++){
    if(s[i] != t[i]){
      flag = 1;
      break;
    }
  }
  
  if(flag == 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}