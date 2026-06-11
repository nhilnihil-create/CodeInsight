#include <bits/stdc++.h>
using namespace std;
int INF=1e9+7;
int main(){
  int N;cin>>N;
  vector<long long>A(60);
  for(int i=0;i<N;i++){
    long long a;cin>>a;
    for(int j=0;j<60;j++)
      if(a&(1ll<<j))A[j]++;
  }
  long long ans=0;long long count=1;
  for(int i=0;i<60;i++){
    ans+=(A[i]*(N-A[i]))%INF*count;
    ans%=INF;
    count=count*2%INF;
  }
  cout<<ans<<endl;
}