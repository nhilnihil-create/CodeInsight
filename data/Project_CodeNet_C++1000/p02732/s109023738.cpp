#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  int A[N];
  for(int i=0;i<N;i++) cin>>A[i];
  long B[N+1];
  for(int i=0;i<=N;i++) B[i]=0;
  for(int i=0;i<N;i++) B[A[i]]++;
  long count=0;
  for(int j=1;j<=N;j++) count += B[j]*(B[j]-1)/2;
 //コードテスト用 cout<<'N'<<count<<endl;
  for(int i=0;i<N;i++){
    int X=A[i];
    long Y=B[X]-1;
    cout<<count-Y<<endl;
  }
}