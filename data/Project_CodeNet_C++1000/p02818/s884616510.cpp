#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int a,b,k;
  cin>>a>>b>>k;
  if(a+b<k) cout<<"0"<<" "<<"0"<<endl;
  else if(a+b>=k&&a>=k) cout<<a-k<<" "<<b<<endl;
  else cout<<"0"<<" "<<b-(k-a)<<endl;
}