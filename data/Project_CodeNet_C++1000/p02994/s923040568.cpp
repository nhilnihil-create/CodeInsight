#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,L;
  cin >> N >>L;
  int sum=0;
  for(int i=0;i<N;i++){
    sum+=L+i;
  }
  if(0<=L){
    sum-=L;
  }
  else if(L+N-1<=0){
    sum-=L+N-1;
  }
  cout << sum << endl;
}
    
    
  