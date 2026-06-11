#include <bits/stdc++.h>
using namespace std;
#include <math.h>
const int64_t INF=9999999999999999;
int main() {
 int N;
 cin>>N;
 vector<int>A(N);
 vector<double>C(N);
 for(int i=0;i<N;i++){
     cin>>A[i];
     C[i]=1/(double)(A[i]);
 }
 double sum=0;
 for(int i=0;i<N;i++){
     sum+=C[i];
 }
 cout << fixed << setprecision(7);
 cout<<1/sum<<endl;
 return 0;}