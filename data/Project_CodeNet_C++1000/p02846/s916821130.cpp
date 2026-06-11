#include <bits/stdc++.h>
using namespace std;

long t1,t2,a1,a2,b1,b2,ans=0;


int main() {
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  if(a1>b1) {
    swap(a1,b1);
    swap(a2,b2);
  }
  if((t1*a1)+(t2*a2)>(t1*b1)+(t2*b2)) {
    ans=((b1-a1)*t1)/((a1-b1)*t1+(a2-b2)*t2)*2;
    if(((b1-a1)*t1)%((a1-b1)*t1+(a2-b2)*t2)!=0) ans++;
  }
  if((t1*a1)+(t2*a2)==(t1*b1)+(t2*b2)) {
    ans=-1;
  }
  if(ans>=0) cout << ans << endl;
  else cout << "infinity" << endl;
}