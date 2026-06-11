#include <bits/stdc++.h>
using namespace std;


int main() {
  int A,B,C,K;
  cin>>A>>B>>C>>K;
  
  int res=0;
  while(B<=A){
    B*=2; res+=1;
    if(res>K){cout<<"No"<<endl; return 0;}
  }
  while(C<=B){
    C*=2; res+=1;
    if(res>K){cout<<"No"<<endl; return 0;}
  }
  cout<<"Yes"<<endl;
}
