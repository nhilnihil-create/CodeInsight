#include<bits/stdc++.h>
using namespace std;
int main(){
  int A; int B; int C; int D; int K;
  cin>>A>>B>>C>>D>>K;
  int S=60*A+B; int T=60*C+D;
   if(A>C)
  T+=60*24;
  cout<<T-S-K<<endl;
}
