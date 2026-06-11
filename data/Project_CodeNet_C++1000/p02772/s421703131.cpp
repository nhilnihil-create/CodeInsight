#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  
  bool can=true;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    if(a%2==1) continue;
    if(a%3!=0&&a%5!=0){
      can=false;
      break;
    }
  }
  if(can) cout<<"APPROVED"<<endl;
  else cout<<"DENIED"<<endl;
    
  
  
}
