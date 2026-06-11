#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,n;
  cin>>h>>n;
  long long wa=0;
  for(int i=0;i<n;i++){
    long long x;
    cin>>x;
    wa+=x;
  }
  if(h<=wa)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}