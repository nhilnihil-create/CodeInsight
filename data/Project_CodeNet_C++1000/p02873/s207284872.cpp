#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>
#define int ll

main(){
  string s;
  cin>>s;
  int n=s.size();
  int ans=0;
  int right=0, left=0;
  rep(i,n){
    if(s[i]=='<'){
      if(right!=0){
        int x=max(right,left),y=min(right,left);
        ans+=x*(x+1)/2+y*(y-1)/2;
        right=0; left=0;
      }
      left++;
    }
    if(s[i]=='>'){
      right++;
    }
  }
  int x=max(right,left),y=min(right,left);
  ans+=x*(x+1)/2+y*(y-1)/2;
  cout<<ans<<endl;
}