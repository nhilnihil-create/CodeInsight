#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,A,f=0;
  cin>>N;
  vector<int> Ao(N);
  for(int i=0;i<N;i++){
    cin>>A;
    if(A%2==0){
      if(A%3!=0&&A%5!=0) f=1;
    }  
  }
  
  
  
  if(f==1) cout<<"DENIED";
  else cout<<"APPROVED";
  

}