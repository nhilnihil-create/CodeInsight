#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t S;
  cin>>S;
  int64_t A=sqrt(S);
  if(A*A>S){
    A--;
  }
  if(A*A==S){
    cout<<"0"<<" "<<"0"<<" "<<A<<" "<<"0"<<" "<<"0"<<" "<<A<<endl;
  }
  else if(A*(A+1)>=S){
    cout<<"0"<<" "<<"0"<<" "<<A<<" "<<A*(A+1)-S<<" "<<"1"<<" "<<A+1<<endl;
  }
  else{
    cout<<"0"<<" "<<"0"<<" "<<A+1<<" "<<(A+1)*(A+1)-S<<" "<<"1"<<" "<<A+1<<endl;
  }
    
}