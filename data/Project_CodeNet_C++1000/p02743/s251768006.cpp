#include<bits/stdc++.h>
using namespace std;
int main(void){
  long long a,b,c; cin>>a>>b>>c;
  if(c<=a||c<=b||(c-a-b)*(c-a-b)<=4*a*b) cout<<"No"; else cout<<"Yes";
  return 0;
}
