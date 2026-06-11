#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  int n;
  string s[100010];
  cin>>n;
  rep(i,n)cin>>s[i];

  rep(i,n)sort(s[i].begin(),s[i].end());
  sort(s,s+n);
  //  rep(i,n)cout<<s[i]<<endl;


  int start=0;
  ll ans=0;
  while(start<n){
    int plus=1;
    while(s[start]==s[start+1]){
      ans+=plus;
      plus++;
      start++;
    }
    start++;
  }


  cout<<ans<<endl;

  return 0;
}
