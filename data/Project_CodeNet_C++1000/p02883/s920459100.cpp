#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N,K;
  cin>>N>>K;
  vector<int64_t>A(N);
  vector<int64_t>F(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  sort(A.begin(),A.end());
    for(int64_t i=0;i<N;i++)
    cin>>F.at(i);
  sort(F.begin(),F.end());
  reverse(F.begin(),F.end());
  int64_t left=-1;int64_t right=1000000000000;
  while(1<right-left){
  int64_t mid=left+(right-left)/2;
    int64_t sum=0;
    for(int i=0;i<N;i++){
    int64_t b=mid/F[i];
      b=A[i]-b;
      if(0<=b)sum+=b;
    }
      
    if(sum<=K)
      right=mid;
    else
      left=mid;
  }cout<<right<<endl;
  
   return 0;
}