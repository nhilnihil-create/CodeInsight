#include<bits/stdc++.h>
using namespace std;

int main(){
  long N,K;cin>>N>>K;
  long ans1=N%K;
  long ans2=K-ans1;
  cout<<(ans1<ans2 ? ans1:ans2)<<endl;
}
  