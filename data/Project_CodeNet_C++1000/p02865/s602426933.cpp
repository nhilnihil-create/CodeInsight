#include<bits/stdc++.h>
using namespace std;
int main(){
  int x;
  cin >>x;
  if(x%2==0){
  x=x-2;
  cout<<x/2<<endl;
  }
  else{
  x=x-1;
  cout<<x/2<<endl;
  }
}