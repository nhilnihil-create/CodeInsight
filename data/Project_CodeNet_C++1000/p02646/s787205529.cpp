#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(20);
  int a, b, v, w, t;
  cin>>a>>v>>b>>w>>t;
  int d = abs(a-b);
  int s = v - w;
  if(s<0) {
    cout<<"NO"<<endl;
    return 0;
  }
  if(s*1LL*t >= d) {
    cout<<"YES"<<endl;
  }
  else cout<<"NO"<<endl;
}

