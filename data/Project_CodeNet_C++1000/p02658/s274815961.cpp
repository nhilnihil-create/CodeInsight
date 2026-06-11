#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  vector<long double>A(N);
  long double count=0;
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  sort(A.begin(),A.end());
  for(int i=0;i<N;i++){
    if(A[i]==0){cout<<0<<endl; return 0;}
    count+=log10(A[i]);
    if(count>18){
      cout<<"-1"<<endl;
      return 0;
    }
  }
  unsigned long long ans=1;
  for(int i=0;i<N;i++){
    ans*=A[i];
    if(ans>1000000000000000000){cout<<"-1"<<endl;return 0;}
  }
  cout<<ans<<endl;
}