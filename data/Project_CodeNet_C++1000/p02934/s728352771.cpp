#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n;
  cin >>n;
  vector<int> a(n);
  rep(i,n) {
    cin>>a.at(i);
  }
  long double now=0;
  rep(i,n){
    now+=1.0/a[i];
  }
  long double ans=1.0/now;
  cout<<setprecision(10)<<ans<<endl;
}