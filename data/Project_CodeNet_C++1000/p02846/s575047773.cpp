#include <bits/stdc++.h>
using namespace std;
typedef  long long  ll;
int main(){
  ll t1,t2,a1,a2,b1,b2;
  cin >> t1 >> t2;
  cin >> a1 >> a2;
  cin >> b1 >> b2;
  ll tmp;
  ll asd=0;
  //tmp = (b1-a1)*t1+(b2-a2)*t2;
  //cout << (b1-a1)*t1 << endl;
  //cout << b2 - a2 << endl;
  //cout << (b2-a2)*t2 << endl;
  //cout << tmp << endl;
  if((a1-b1)*t1==(b2-a2)*t2)cout << "infinity" << endl;
  else if(a1<b1&&(((b1-a1)*t1+(b2-a2)*t2)>0)) cout << 0 << endl;
  else if(b1<a1&&((a1-b1)*t1+(a2-b2)*t2)>0) cout << 0 << endl;
  else if(b1<a1){
    //tmp = (b1*t1+b2*t2)-(a1*t1+a2*t2);
    tmp = (b1-a1)*t1+(b2-a2)*t2;
    if(((a1-b1)*t1)%tmp==0)asd=1;
    cout << 1 + 2*(((a1-b1)*t1)/tmp)-asd << endl;
  }
  else if(a1<b1){
    //tmp = (a1*t1+a2*t2)-(b1*t1+b2*t2);
    tmp = (a1-b1)*t1+(a2-b2)*t2;
    if(((b1-a1)*t1)%tmp==0)asd=1;
    cout << 1 + 2*(((b1-a1)*t1)/tmp)-asd << endl;
  }
}
