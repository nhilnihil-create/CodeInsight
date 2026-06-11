#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N;cin>>N;
  vector<int64_t>A(N+1);
  for(int i=0;i<=N;i++)
    cin>>A.at(i);
  if(A.at(0)!=0){
  if(N==0 && A.at(0)==1)cout<<1<<endl;
    else
      cout<<-1<<endl;
  }else{
vector<int64_t>B(N);B.at(N-1)=A.at(N);
    for(int i=N-2;0<=i;i--)
      B.at(i)=B.at(i+1)+A.at(i+1);
    vector<int64_t>C(N);C[0]=1;bool x=true;
    for(int i=1;i<N;i++){
    if(2*C[i-1]-A[i]<=B[i] && 1<=2*C[i-1]-A[i])
      C[i]=2*C[i-1]-A[i];
      else if(B[i]<2*C[i-1]-A[i])
        C[i]=B[i];
      else{x=false;break;}
    }
      if(!x)cout<<-1<<endl;
      else{
        if(2*C[N-1]<A[N])cout<<-1<<endl;
        else{
      int64_t ans=0;
        for(int i=0;i<N;i++){ans+=(A.at(i+1)+C.at(i));}
        cout<<ans<<endl;
        }
      }
    }
  return 0;
}