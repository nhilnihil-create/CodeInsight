#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t f=100, X;
  cin>>X;

  int year=0;
  while(f<X){
    f += f/100;
    year++;
  }
  cout<<year<<endl;
}