#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  
  string s[n+1];
  for(int i = 0; i < n; i++){
    cin >> s[i];
  }
  
  sort(s,s+n);
  int ans = 1,maxans = 0;
  for(int i = 0; i < n; i++){
    if(s[i] == s[i+1]){
      ans++;
      continue;
    }
    if(ans > maxans){
      maxans = ans;
    }
    ans = 1;
  }
  
  ans = 1;
  for(int i = 0; i < n; i++){
    if(s[i] == s[i+1]){
      ans++;
      continue;
    }
    if(ans == maxans){
      cout << s[i] << endl;
    }
    ans = 1;
  }
      
}