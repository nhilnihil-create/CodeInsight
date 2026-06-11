#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll t1,t2,a1,a2,b1,b2;cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  if(t1*a1+t2*a2==t1*b1+t2*b2){
    cout << "infinity" << endl;
    return 0;
  }
  ll c1=a1-b1;
  ll c2=a2-b2;
  if(c1<0){
    c1*=-1;
    c2*=-1;
  }
  if(c1*t1+c2*t2>0){
    cout << 0 << endl;
    return 0;
  }
  ll u=c1*t1;
  ll v=c1*t1+c2*t2;
  if(abs(u)%abs(v)==0){
    cout << abs(u)/abs(v)*2 << endl;
  }
  else{
    cout << abs(u)/abs(v)*2+1 << endl;
  }
}