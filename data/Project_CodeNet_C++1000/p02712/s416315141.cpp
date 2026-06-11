#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n; cin>>n;
  long long res=0;
  for(int i=1; i<=n; ++i) if(i%3>0&&i%5>0) res+=i;
  cout<<res;
  return 0;
}
