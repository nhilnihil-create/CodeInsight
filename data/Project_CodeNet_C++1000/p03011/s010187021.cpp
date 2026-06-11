#include<bits/stdc++.h>
using namespace std;

int main(){
  int P,Q,R;
  cin>>P>>Q>>R;
  int ans=100000;
  int PQ=P+Q;
  int PR=P+R;
  int QR=Q+R;
  ans=min({ans,PQ,PR,QR});
  cout<<ans<<endl;
}
  