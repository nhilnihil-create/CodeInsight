#include<iostream>
#include <cstdlib>
using namespace std;

int main(){
  int n;
  cin >> n;
  while(n>0){
    n-=1000;
  }
  cout << abs(n) << endl;
}