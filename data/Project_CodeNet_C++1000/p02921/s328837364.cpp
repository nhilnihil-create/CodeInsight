#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,LL> PL;

const int MOD=1000000007;
int INF=100100100;
int main(){
  string s,t;
  cin>>s>>t;
  int ans=0;
  for(int i=0;i<3;i++){
    if(s[i]==t[i])ans++;
  }
  cout<<ans<<endl;
  
  return 0;
}