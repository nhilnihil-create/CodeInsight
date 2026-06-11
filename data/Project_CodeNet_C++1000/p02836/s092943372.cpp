#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  
  string com = s;
  reverse(com.begin(),com.end());
  int ans = 0;
  int n = s.size();
  for(int i = 0; i < n/2; i++){
    if(s[i] != com[i]){
      ans++;
    }
  }
  
  cout << ans << endl;
}