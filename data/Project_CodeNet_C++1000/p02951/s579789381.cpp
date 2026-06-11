#include<iostream>
using namespace std;
 
int A;
int B;
int C;
 
int main(){
  cin >> A >> B >> C;
  if(C - (A - B) >= 0){
    cout << C - (A - B);
  }
  else{
    cout << "0";
  }
}