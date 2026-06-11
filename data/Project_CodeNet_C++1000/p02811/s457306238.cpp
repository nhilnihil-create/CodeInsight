#include <iostream>
using namespace std;

int K;
int X;

int main(){
  cin >> K >> X;
  if(K * 500 >= X){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
}