#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int unsigned long long
#define endl "\n"
using namespace std;

int32_t main() {
  ios;
  int t = 1;
  // cin>>t;
  while(t--) {
    int a,b,k;
    cin>>a>>b>>k;
    if(k <= a) {
      a-=k;
    } else {
      k-=a;
      a = 0;
      if(k <= b)
        b-=k;
      else
        b = 0;
    }
    cout<<a<<" "<<b;
    cout<<endl;
  }
  return 0;
}