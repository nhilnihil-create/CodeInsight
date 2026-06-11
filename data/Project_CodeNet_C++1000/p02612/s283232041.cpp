#include <bits/stdc++.h>
using namespace std;
int main(){
  int price=0;
  cin>>price;
  int N=10;
  int f=0;
  for(int i=0;i<N;i++){
    if(f*1000-price>=0){
      break;
    }
    f++;
  }
  cout<<f*1000-price<<endl;
}