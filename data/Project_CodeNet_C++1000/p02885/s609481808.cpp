#include<iostream>
using namespace std;
int main(){
  int a,b;
  cin >> a >> b;
  int c=2*b;
  if(a<=c){
    cout << '0' << endl;
  }
  else{
    cout << a-c << endl;
  }
}