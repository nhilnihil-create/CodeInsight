#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,A;
  cin>>N;
  A=N%10;
  switch(A){
    case 2:
    case 4:
    case 5:
    case 7:
    case 9:
      cout<<"hon"<<endl;
      break;
    case 0:
    case 1:
    case 6:
    case 8:
      cout<<"pon"<<endl;
      break;
    default:
      cout<<"bon"<<endl;
  }
}