#include<bits/stdc++.h>
using namespace std;

int main(void){
  long long a,b,n; cin>>a>>b>>n;
  long long res;
  if(n/b==0) res=a*n/b-a*(n/b);
  else res=a*(n/b*b-1)/b-a*((n/b*b-1)/b);
  cout<<res<<endl;
  return 0;
}
