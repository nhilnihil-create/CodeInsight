#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  string s;
  cin>>s;
  int n=s.size(),ans=0;
  rep(i,n){
    if(s[i]!=s[n-1-i])ans++;
  }
  cout<<ans/2<<endl;
}