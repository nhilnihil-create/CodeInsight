#include <bits/stdc++.h>
using namespace std;
#include <math.h>
const int64_t INF=9999999999999999;
int main() {
 int N,X;
 cin>>N>>X;
 vector<int>L(N);
 for(int i=0;i<N;i++){
    cin>>L[i];
 }
 vector<int>D(N+1);
 int count=0;
 for(int i=0;i<N+1;i++){
    if(i>=1){D[i]=D[i-1]+L[i-1];}
    if(D[i]<=X){count++;}
 }
 cout<<count<<endl;
 return 0;}