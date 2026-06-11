#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){

  int N;
  cin>>N;
  vector<long long>A(N);
  long long allsum=0;
  for(int i=0;i<=N-1;i++){
  
    cin>>A[i];
    allsum+=A[i];
  }
  long long ans=allsum;
  long long check=0;
  for(int i=0;i<=N-1;i++){
  
    check+=A[i];
    allsum-=A[i];
    if(ans>abs(check-allsum))ans=abs(check-allsum);
  }
  cout<<ans;
  return 0;
}