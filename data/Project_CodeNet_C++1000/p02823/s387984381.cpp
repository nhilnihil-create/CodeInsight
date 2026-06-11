#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n,a,b;
  cin>>n>>a>>b;
  long long x=b-a;
  if(x%2==0) cout<<x/2<<endl;
  else cout<<(b-a-1)/2+min(a-1,n-b)+1<<endl;
}