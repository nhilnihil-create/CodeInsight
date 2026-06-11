#include <bits/stdc++.h>
using namespace std;

int main() {
  long long h,w;
  cin >>h>>w;
  if(h==1||w==1){
    cout<<1<<endl;
    return 0;
  }
  long long kotae=h*w/2;
  if(h*w%2==1)kotae++;
  cout<<kotae<<endl;
  return 0;
}