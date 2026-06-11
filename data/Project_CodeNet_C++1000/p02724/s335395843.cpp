#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;cin>>n;
  int ans=(n/500)*1000;
  ans+=((n%500)/5)*5;
  cout<<ans<<endl;
  return 0;
}