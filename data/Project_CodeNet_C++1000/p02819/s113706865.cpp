#include <bits/stdc++.h>

using namespace std;
int n=1e5+5;
bool prime[100005];
int main()
{
  memset(prime, true, sizeof(prime));
  int x;
  cin>>x;
  prime[1]=false;
  for(int i=2;i*i<=n;++i){
      if(prime[i]){
          for(int j=i*i;j<=n;j+=i){
              prime[j]=false;
          }
      }
  }
  if(prime[x])cout<<x;
  else {
      for(int i=x;;++i){
          if(prime[i]){
              cout<<i;
              return 0;
          }
      }
  }
   return 0;
}