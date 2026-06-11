#include<bits/stdc++.h>
#include<cstdlib>
#include<cmath>
using namespace std;
int main(){
  int N; int K; cin>>N>>K;
  int L=1;
  while(N/K!=0){
    L++;
    N/=K;
  }
  cout<<L<<endl;
}