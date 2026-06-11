#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n;
  cin>>n;
  ll ans=0;
  rep(i,n){
    int a;
    cin>>a;
    ans=ans^a;
  }
  if(ans==0)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}