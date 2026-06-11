#include <iostream>
#include <vector>

using namespace std;
#define ll long long

int max(int a,int b){
  if(a>b){
    return a;
  }else{
    return b;
  }
}

int main(void){
  int a,b,c;
  cin >> a >> b >> c;
  cout << max(c -(a-b),0) << endl;
  return 0;
}