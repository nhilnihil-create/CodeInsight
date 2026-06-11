

#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;
typedef long long ll;
 
int main(){
int N;
cin>>N;
vector<int>A(N);
 
for(int i=0;i<N;i++){
   cin>>A[i];
}
vector<int>B=A;
sort(B.rbegin(),B.rend());
 
for(int i=0;i<N;i++){
   int a=B[0];
   if(B[0]==A[i]){
      a=B[1];
   }
   cout<<a<<endl;
 
}
 
return 0;
}