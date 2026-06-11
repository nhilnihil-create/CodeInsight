#include <bits/stdc++.h>
using namespace std;

int main() {
int N;
  cin>>N;
  vector<int>moji(N);
  for(int i=0;i<N;i++){
  	cin>>moji.at(i);
  }
 bool nazo=true;
   for(int i=0;i<N;i++){
  	if(moji.at(i)%2==0){
      if(moji.at(i)%3==0 || moji.at(i)%5==0){
      nazo=true;
      }
      else{
      nazo=false;
        break;
      }
    }
  }
  
if(nazo){
cout<<"APPROVED "<<endl;
}
  else{
  cout<<"DENIED "<<endl;
  }
  
}