#include <bits/stdc++.h>
using namespace std;
#include <math.h>
const int64_t INF=9999999999999999;
int main() {
 int N;
 cin>>N;
 vector<int>A(N);
 vector<int>B(N);
 vector<int>C(N-1);
 for(int i=0;i<N;i++){
     cin>>A[i];
 }
 for(int i=0;i<N;i++){
     cin>>B[i];
 }
 for(int i=0;i<N-1;i++){
     cin>>C[i];
 } 
 int sum=0;
 for(int i=0;i<N;i++){
  sum+=B[A[i]-1];
  if(i<N-1&&A[i+1]-A[i]==1){sum+=C[A[i]-1];}
 }
cout<<sum<<endl;
 return 0;}