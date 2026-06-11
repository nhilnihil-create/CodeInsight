#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <iostream>
#include <ctype.h>
#include <string>
typedef long long ll;
using namespace std;

int main(){
  double n,m,ans=0;
  cin>>n;
  rep(i,n){
    cin>>m;
    m=1/m;
    ans+=m;
  }
  cout<<fixed<<setprecision(8);
  ans=1/ans;
  cout<<ans;
}
