#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;


int main(){
  string s;
  cin >>s;
  int ans=0;
  if(s[0]==s[1] && s[2]==s[3])ans++;
  if(s[0]==s[3] && s[1]==s[2])ans++;
  if(s[0]==s[2] && s[1]==s[3])ans++;
  if(ans==1){cout << "Yes" << endl;}else{cout << "No" <<endl;}
}