#include <iostream>
using namespace std;
 
int main(){
    //入力を受け取る
    int N;
    cin >> N;
  
  if (N % 1000 == 0) {
    cout << "0" << endl;
  }
  else {
    cout << ((N+1000)/1000)*1000-N << endl;
  } 
}