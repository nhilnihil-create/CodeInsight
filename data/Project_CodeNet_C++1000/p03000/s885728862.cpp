#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,x;
  cin>>n>>x;
  vector<int>vec(n);
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  int cnt=1;
  int a=0;
  for(int i=0;i<n;i++){
    a+=vec[i];
    if(a<=x)cnt++;
  }
  cout<<cnt<<endl;
}