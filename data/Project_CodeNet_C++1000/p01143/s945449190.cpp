#include<bits/stdc++.h>
using namespace std;



int main(){
  int N,M,P;

  
  while(true){
    cin >> N >> M >> P;

    if(N + M + P == 0) break;
    
    int a,X, sum=0;

    for(int i=0;i<N;++i){
      cin >> a;
      sum += a;
      
      if(i == M-1){
	X = a;
      }
    }
    
    sum = sum*(100 - P);
    if(X==0){cout<<0<<endl; continue;}
    
    cout << sum/X << endl;
      
  }
  
  return 0;
}

