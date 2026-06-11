#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,a;
  cin>>n;
  double d=0;
  for(int i=0;i<n;i++){
    cin>>a;
    d+=1.0/a;
  };
  cout<<fixed<<setprecision(10)<<1.0/d<<endl;
}