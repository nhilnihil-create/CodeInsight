#include <bits/stdc++.h>
using namespace std;

#define int long long
int A[223456];

signed main(){
  int n,p;string s;cin>>n>>p>>s;
  if(p==2||p==5){
    int a=0;
    for(int i=0;i<s.size();i++)if((s[i]-'0')%p==0)a+=i+1;
    cout<<a<<endl;return 0;
  }
  reverse(s.begin(),s.end());
  for(int i=0,t=1;i<s.size();i++){
    int a=s[i]-'0';
    A[i+1]=(A[i]+a*t)%p;
    (t*=10)%=p;
  }
  map<int,int> m;
  for(int i=0;i<=s.size();i++)m[A[i]]++;
  int ans=0;
  for(auto p:m)ans+=p.second*(p.second-1)/2;
  cout<<ans<<endl;
}
