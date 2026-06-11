#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,n,maxA=0,maxAi=0,submaxA=0; cin>>n;
  for(int i=0;i<n;i++){
    cin>>a;
    if(maxA<=a&&submaxA<=a){
      submaxA=maxA;
      maxA=a;
      maxAi=i;
    }else if(submaxA<=a){
      submaxA=a;
    }
  }
  for(int i=0;i<n;i++) cout<<(maxAi==i?submaxA:maxA)<<endl;
}