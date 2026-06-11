#include<iostream>
using namespace std;

int main(){
  char moji;
  cin >> moji;
  
  if ('a' <= moji && moji <= 'z'){
    cout << "a" << endl;
  }
  else{
    cout << "A" << endl;
  }
  
  return 0;
}
