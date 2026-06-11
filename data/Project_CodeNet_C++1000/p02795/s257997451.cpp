#include<bits/stdc++.h>
using namespace std;
int main(){
int A; int B; int C; cin>>A>>B>>C;
  int L=max(A,B);
  int K=0;
  int X=0;
  while(K<C){
    X++;
    K+=L;
  }
  cout<<X<<endl;
}
