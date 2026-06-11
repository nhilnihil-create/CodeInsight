#include<bits/stdc++.h>
using namespace std;

int main() {
  long long t1,t2;
  cin >> t1 >> t2;
  long long a1,a2,b1,b2;
  cin >> a1 >> a2 >> b1 >> b2;
  long long p,q;
  if(a1>b1) {
    p=t1*(a1-b1);
    q=t2*(a2-b2);
  }
  else {
    p=t1*(b1-a1);
    q=t2*(b2-a2);
  }
  if(p+q==0) {
    cout << "infinity" << endl;
  }
  else if(p+q>0) {
    cout << 0 << endl;
  }
  else {
    long long ans=2*(p/(-(p+q)));
    if(p%(-(p+q))!=0) {
      ans++;
    }
    cout << ans << endl;
  }
}