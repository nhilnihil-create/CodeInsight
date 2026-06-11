#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll A,B;
  cin>>A>>B;
  ll a,b;
  a=A/0.08;
  b=(A+1)/0.08;
  for(ll i=a;i<b+2;i++){
    ll c,d;
    c=0.08*i;
    d=0.1*i;
    if(c==A&&d==B){
      cout<<i<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
}
