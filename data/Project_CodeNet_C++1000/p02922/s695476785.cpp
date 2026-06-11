#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;cin>>A>>B;
  int preuse=1;
  int ans=0;
  while(true){
    if(B==1) break;
    ans++;
    preuse += A-1;
    if(preuse>=B) break;
  }
  cout<<ans<<endl;
}
