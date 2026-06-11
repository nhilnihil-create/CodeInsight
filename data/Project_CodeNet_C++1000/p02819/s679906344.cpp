#include<bits/stdc++.h>
using namespace std;
int main(void){
  int x; cin>>x;
  vector<bool> a(x*10+1,false);
  vector<int> b;
  for(int i=2; i<=x*10; ++i){
    if(a[i]==false){
      b.push_back(i);
      for(int j=2; i*j<=x*10; ++j) a[i*j]=true;
    }
  }
  cout<<*lower_bound(b.begin(),b.end(),x);
  return 0;
}