#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;	cin >> n;
  vector<char>	s(n);
  for(int i=0;i<n;i++)	cin >> s[i];
  
  int ans=n;
  for(int i=1;i<n;i++){
    if(s[i]==s[i-1])	ans--;
  }
  cout << ans;
}