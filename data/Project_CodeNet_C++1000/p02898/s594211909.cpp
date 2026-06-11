#include <bits/stdc++.h>
using namespace std;
#include <math.h>
const int64_t INF=9999999999999999;
int main() {
 int N,K;
 cin>>N>>K;
 vector<int>h(N);
 int count=0;
 for(int i=0;i<N;i++){
    cin>>h[i];
    if(h[i]>=K){count++;}
 }
 
 cout<<count<<endl;
 return 0;}