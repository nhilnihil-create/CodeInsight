#include <bits/stdc++.h>
using namespace std;
#include <math.h>
const int64_t INF=9999999999999999;
int main() {
 int N;
 cin>>N;
 double A; double sum=0.0;
 for(int i=0;i<N;i++){
   cin>>A;
   sum+=1/A;
 }

 cout << fixed << setprecision(7);
 cout<<1/sum<<endl;
 return 0;}