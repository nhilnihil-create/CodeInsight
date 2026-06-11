#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
  
  int a,b,c,k;
  cin>>a>>b>>c>>k;
  while(k--){
    if(a>=b) b*=2;
    else if(b>=c) c*=2;
    else break;
  }
  if(a<b&&b<c)cout <<"Yes"<<endl;
  else cout<<"No"<<endl;
  
}
