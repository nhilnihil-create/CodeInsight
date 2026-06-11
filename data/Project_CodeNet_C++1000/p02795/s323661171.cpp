#include<bits/stdc++.h>
using namespace std;


int main(){
  int h,w,n; cin>>h>>w>>n;
  int x = max(h,w);
  cout<<( (x + n-1)/x)<<endl;
  return 0;
}
