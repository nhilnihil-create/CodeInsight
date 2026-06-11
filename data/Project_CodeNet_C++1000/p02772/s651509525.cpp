#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  int n;
  cin>>n;
  bool ans=1;
  rep(i,n){
    int a;
    cin>>a;
    if(a%2==0){
      if(a%3!=0 && a%5!=0) ans=0;
    }
  }
  if(ans) cout<<"APPROVED"<<endl;
  else cout<<"DENIED"<<endl;
}