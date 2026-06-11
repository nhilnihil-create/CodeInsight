#include <bits/stdc++.h>
using namespace std;

int main() {
  long X;cin>>X;
  long N=100;
  int ans=0;
  while(true){
    N = N + N/100;
    ans++;
    if(N>=X) break;
  }
  cout<<ans<<endl;
    
}
