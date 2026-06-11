#include<iostream>
using namespace std;
int main(){
  long long x;
  cin >> x;
  long long m=100;
  int i;
  for(i=0;m<x;i++){
    m=m+m/100;
  }
  cout << i << endl;
}