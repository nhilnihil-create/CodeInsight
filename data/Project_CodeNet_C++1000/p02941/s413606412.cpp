#include<bits/stdc++.h>
using namespace std;
int main(){
int N;cin>>N;
  vector<int64_t>A(N);
  vector<int64_t>B(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  for(int i=0;i<N;i++)
    cin>>B.at(i);
  bool update=true;
  int64_t ans=0;
  while(update){
  update=false;
    for(int i=0;i<N;i++){
    int64_t a=B[(N+i-1)%N];
      int64_t b=B[i];
      int64_t c=B[(N+i+1)%N];
      if(a+c<b && A[i]<=b-a-c){
      int64_t d=(b-A.at(i))/(a+c);
        ans+=d;update=true;
        B.at(i)-=d*(a+c);
      }
    }
  
  }bool x=true;
  for(int i=0;i<N;i++)
    if(A[i]!=B[i]){x=false;break;}
  if(!x)
    cout<<-1<<endl;
  else
    cout<<ans<<endl;
return 0;
}