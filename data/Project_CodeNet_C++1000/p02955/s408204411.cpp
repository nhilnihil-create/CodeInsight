#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,k,a_sum=0;
  cin >> n >> k;
  vector<long> a(n);
  vector<long> b;
  for(int i=0;i<n;i++) cin >> a[i];

  for(int i=0;i<n;i++) a_sum+=a[i];
  for(int i=1;i*i<=a_sum;i++) {
    if(a_sum%i==0) {
      b.push_back(i);
      if(i*i!=a_sum) b.push_back(a_sum/i);
    }
  }
  sort(b.begin(),b.end());
  for(long i=b.size()-1;true;i--) {
    vector<long> aa(n);
    for(long j=0;j<n;j++) aa[j]=a[j]%b[i];
    sort(aa.begin(),aa.end());
    long be=0,en=n-1,co=0;
    while(true) {
      if(be>en) break;
      if(aa[be]==0) be++;
      else break;
    }
    while(be<=en&&co<=k) {
      if(aa[be]==b[i]-aa[en]) {
        co+=aa[be];
        be++;
        en--;
      } else if(aa[be]>b[i]-aa[en]) {
        co+=b[i]-aa[en];
        aa[be]-=b[i]-aa[en];
        en--;
      } else {
        co+=aa[be];
        aa[en]+=aa[be];
        be++;
      }
    }
    if(co<=k) {
      cout << b[i] << endl;
      break;
    }
  }
}