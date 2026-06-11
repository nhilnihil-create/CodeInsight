#include <iostream>
int count=0;

int MR(int N,int Q,int* A,int* B,int* C,int* D,int* seq,int pt){
 int res=0;
 count++;
 if(pt==-1){
  for(int i=0;i<Q;i++){
   if(seq[B[i]]-seq[A[i]]==C[i]){
    res+=D[i];
   }
  }
 }else{
  int ot=0;
  for(int i=1;i<=seq[pt+1];i++){
   seq[pt]=i;
   ot=MR(N,Q,A,B,C,D,seq,pt-1);
   if(res<ot){
    res=ot;
   }
  }
 }
 return res;
}

int main(){
 int N,M,Q;
 std::cin>>N>>M>>Q;
 int* A=new int[Q];
 int* B=new int[Q];
 int* C=new int[Q];
 int* D=new int[Q];
 for(int i=0;i<Q;i++){
  std::cin>>A[i]>>B[i]>>C[i]>>D[i];
 }

 int* seq=new int[N+1];
 seq[N]=M;
 int ans=MR(N,Q,A,B,C,D,seq,N-1);

 std::cout<<ans<<std::endl;
}