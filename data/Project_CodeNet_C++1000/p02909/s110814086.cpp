#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
using ll = long long;
int main(){
  string s;
  cin >> s;
  string ans ="Sunny";
  if(s == "Sunny")ans = "Cloudy";
  else if(s == "Cloudy")ans = "Rainy";
  cout << ans <<endl;
  return 0;
}
