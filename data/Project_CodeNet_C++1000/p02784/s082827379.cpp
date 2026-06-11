#include<bits/stdc++.h>
using namespace std;

int main(){
  int H,N,sum=0;
  cin>>H>>N;
  for(int i=0; i<N; i++){
    int A;
    cin>>A;
    sum+=A;
  }
  cout<<(H-sum<=0?"Yes":"No");
}