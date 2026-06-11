#include <bits/stdc++.h>
using namespace std;

int main(){
  long long l,r;
  cin>>l>>r;
  if(r-l>=2019)cout<<0<<endl;
  else {
    long long kotae=LLONG_MAX;
    for(long long i=l;i<r;i++){
      for(long long j=i+1;j<=r;j++){
        kotae=min(kotae,(i%2019*j)%2019);
      }
    }
    cout<<kotae<<endl;
  }
  return 0;
}
