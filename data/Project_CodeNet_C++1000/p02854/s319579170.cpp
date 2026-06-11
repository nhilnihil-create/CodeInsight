#include <bits/stdc++.h>
using namespace std;
int main(){
  unsigned long long int N;
  cin>>N;
  vector<unsigned long long int>A(N);
  unsigned long long int ans=0;
  for(int i=0;i<N;i++){
    cin>>A[i];
    ans+=A[i];
  }
  unsigned long long int count=0;
  unsigned long long int answer;
  unsigned long long int E;
  for(int i=0;i<N;i++){
    count+=A[i];
    answer=max(ans-count,count)-min(ans-count,count);
    if(i==0)E=answer;
    else E=min(E,answer);
  }
  cout<<E<<endl;
}