#include<bits/stdc++.h>
using namespace std;
#define lol long long
#define inf 1000000007
string m[10000];
lol k[100000];
int main(){
  lol n,a=0,ans=0;
  string s,x;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>m[i]>>k[i];
  }
  cin>>x;
  for(int i=0;i<n;i++){
    if(m[i]==x) a++;
    else if(a>0){
      ans+=k[i];
    }
  }
  cout<<ans<<"\n";
  return(0);
}
