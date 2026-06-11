#include <iostream>

int main(){
 int N;
 std::cin>>N;
 int* A=new int[N+1];
 for(int i=0;i<N+1;i++){
  std::cin>>A[i];
 }
 long long* ub=new long long[N+1];
 ub[N]=A[N];
 for(int i=N-1;i>=0;i--){
  ub[i]+=ub[i+1]+A[i];
 }
 
 long long* node=new long long[N+1];
 node[0]=1;
 long long ans=0;
 int flag=0;
 for(int i=0;i<N;i++){
  //std::cout<<node[i]<<" "<<A[i]<<std::endl;
  if(node[i]>A[i]){
   if((node[i]-A[i])*2<ub[i+1]){
    node[i+1]=(node[i]-A[i])*2;
   }else{
    node[i+1]=ub[i+1];
   }
  }else{
   ans=-1;
   flag=1;
   break;
  }
 }
 if(node[N]!=A[N]){
  ans=-1;
  flag=1;
 }

 if(flag==0){
  for(int i=N;i>=0;i--){
   ans+=node[i];
  }
 }
 std::cout<<ans<<std::endl;
}