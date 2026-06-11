#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  string S;
  cin>>N>>S;
  map<char,int> mp;
  for(char c:S)mp[c]++;
  int ans=mp['R']*mp['G']*mp['B'];
  for(int i=0;i<N-1;i++)
    for(int j=i+1;j<N && j*2-i<N;j++)
      if(S[i]!=S[j] && S[i]!=S[j*2-i] && S[j]!=S[j*2-i])ans--;
  cout<<ans<<endl;
}