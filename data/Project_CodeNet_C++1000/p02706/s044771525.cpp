#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;

int main(){
  int n,m;
  cin>>n>>m;
  ll sum=0;
  rep(i,m){
    int a;
    cin>>a;
    sum+=a;
  }
  if(sum<=n)cout<<n-sum<<endl;
  else cout<<-1<<endl;
  return 0;
}
