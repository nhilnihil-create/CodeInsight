#include <bits/stdc++.h>
using namespace std;
int main(){
  double h,w,n;
  cin>>h>>w>>n;
  double divisor=max(h,w);
    cout<<ceil(n/divisor)<<endl;
  return 0;
}
