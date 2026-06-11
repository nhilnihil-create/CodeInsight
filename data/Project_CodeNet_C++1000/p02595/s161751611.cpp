#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll n,d,dd;
  cin>>n>>d;
  dd=d*d;
  
  ll res=0;
  for(int i=0; i<n; i++){
    ll xi,yi;
    cin>>xi>>yi;
    res += (xi*xi+yi*yi<=dd);
  }
  cout<<res<<endl;
}