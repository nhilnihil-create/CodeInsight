#include<bits/stdc++.h>
using namespace std;

int main(){
 int N;
  cin>>N;
  int A[N];
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  int sum=0;
  for(int i=0;i<N;i++){
    if(A[i]!=i+1){
      sum++;
    }
  }
  if(sum<=2){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}