#include<iostream>
using namespace std;

int A;
int B;

int main(){
  cin >> A >> B;
  if(A % 2 != B % 2){
    cout << "IMPOSSIBLE";
  }
  else{
    cout << (A + B)/2;
  }
}