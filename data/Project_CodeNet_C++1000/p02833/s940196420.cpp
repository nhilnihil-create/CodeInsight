#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N;cin>>N;
  if(N%2==1){puts("0");return 0;}
  long long ans=0;
  for(int i=1;i<26;i++){
    long long count=2ll*(pow(5,i));
    ans+=N/count;
  }
  cout<<ans<<endl;
}