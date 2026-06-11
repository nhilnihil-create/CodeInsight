#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
 ll a,b;
  cin>>a>>b;
  if(a==1&&b==2){
cout<<3<<endl;
  }
  else if(a==2&&b==1){
cout<<3<<endl;
  }
  else if(a==1&&b==3){
cout<<2<<endl;
  }
  else if(a==3&&b==1){
cout<<2<<endl;
  }
  else{
     cout<<1<<endl;
  }
}