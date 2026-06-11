#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin>>n;
  string s; cin>>s;
  vector<vector<int>>suff(n+1,vector<int>(3,0));
  suff[n] = {0,0,0};
  for(int i = n-1; i >= 0 ; i--){
    suff[i] = suff[i+1];
    if(s[i] == 'R')suff[i][0]++;
    if(s[i] == 'G')suff[i][1]++;
    if(s[i] == 'B')suff[i][2]++;
  }
  long long res = 0;
  for(int i = 0 ; i < n ; i++){
    for(int j = i+1 ; j < n ; j++){
      if(s[i] == s[j])continue;
      if('R'!=s[i] && 'R'!=s[j])res+=suff[j][0] - (j+(j-i) < n && s[j + (j-i)]=='R');
      if('G'!=s[i] && 'G'!=s[j])res+=suff[j][1] - (j+(j-i) < n && s[j + (j-i)]=='G');
      if('B'!=s[i] && 'B'!=s[j])res+=suff[j][2] - (j+(j-i) < n && s[j + (j-i)]=='B');
    }
  }
  cout<<res;
}
