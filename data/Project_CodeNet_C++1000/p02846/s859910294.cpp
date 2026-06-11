#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int t1,t2;
  ll a1,a2,b1,b2;
  cin >> t1 >> t2;
  cin >> a1 >> a2;
  cin >> b1 >> b2;

  a1=a1*t1;
  a2=a2*t2;
  b1=b1*t1;
  b2=b2*t2;
  if(a1+a2<b1+b2){
    swap(a1,b1);
    swap(a2,b2);
  }
  if(a1+a2==b1+b2){
    cout << "infinity" << endl;
    return 0;
  }else{
    if(a1>b1){
      cout << "0" << endl;
      return 0;
    }else{
      ll c=b1-a1;
      ll d=(a1+a2)-(b1+b2);
      ll ans;
      if(c%d==0) ans=c/d*2;
      else ans=c/d*2+1;

      cout << ans << endl;
    }
  }
  return 0;
}
