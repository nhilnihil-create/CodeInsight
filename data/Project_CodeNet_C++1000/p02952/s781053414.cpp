#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int main()
{
  int s;
  cin>>s;
  int ans=0;
  for(int i=1;i<=s;i++){
      if((1<=i&&i<10)||(100<=i&&i<1000)||(10000<=i&&i<100000)) ans++;
  }
  cout<<ans;
}