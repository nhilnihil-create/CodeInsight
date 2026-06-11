#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
 ll a,b;
  cin>>a>>b;
  if(a<=2*b){
cout<<0<<endl;
  }
  else{
    cout<<a-2*b<<endl;
  }
}
