#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=0;
  cin >> n;
  vector<long> p(n);
  vector<long> gyakup(n);
  set<long> aaa;
  for(long i=0;i<n;i++) cin >> p[i];
  
  for(long i=0;i<n;i++) gyakup[n-p[i]]=i;
  for(long i=0;i<n;i++) {
    aaa.insert(gyakup[i]);
    long a=-1,b=-1,c=gyakup[i],d=-1,e=n;
    auto itr=aaa.lower_bound(gyakup[i]);
    if(itr!=aaa.begin()) {
      itr--;
      b=*itr;
    }
    if(itr!=aaa.begin()) {
      itr--;
      a=*itr;
    }
    itr=aaa.upper_bound(gyakup[i]);
    if(itr!=aaa.end()) {
      d=*itr;
      itr++;
    }
    if(itr!=aaa.end()) {
      e=*itr;
    }

    if(b!=-1) {
      if(d!=-1) ans+=(n-i)*(b-a)*(d-c);
      else ans+=(n-i)*(b-a)*(n-c);
    }
    if(d!=-1) {
      if(b!=-1) ans+=(n-i)*(e-d)*(c-b);
      else ans+=(n-i)*(e-d)*(c+1);
    }
  }
  cout << ans << endl;
}