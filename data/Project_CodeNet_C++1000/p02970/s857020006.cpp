#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,d,cnt=0;
  cin>>n>>d;
  bool ok[n+1];
  memset(ok,false,sizeof ok);
  for(int i=1;i<=n;i++){
    if(!ok[i]){
      cnt++;
      for(int j=i;j<=min(n,i+2*d);j++) ok[j]=true;
    }
  }
  cout<<cnt;
  return(0);
}