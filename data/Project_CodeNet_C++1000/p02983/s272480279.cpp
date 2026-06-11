#include<bits/stdc++.h>
using namespace std;

int main() {
  int L,R;cin>>L>>R;
  int ans=2018;
  int Rf=min(R-L,2019);
  for(int i=L;i<L+Rf;i++){
    for(int j=i+1;j<=L+Rf;j++){
      int ansy=((i%2019)*(j%2019))%2019;
      ans=min(ansy,ans);
    }
  }
  cout<<ans<<endl;
}
