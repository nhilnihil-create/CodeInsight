#include <bits/stdc++.h>
using namespace std;
int main(){
  int k,a,b;
cin>>k>>a>>b;
  if(b-a>=k-a%k||a%k==0)cout<<"OK";
  else cout<<"NG";
  return 0;
}