#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  for(int i=1;i<11;i++){
  if(1000*i-N<1000&&0<=1000*i-N){
   cout<<1000*i-N<<endl;
    break;
  }
  }

}
