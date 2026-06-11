#include<iostream>
using namespace std;
 
int main(){
  int k, x, a;
  cin >> k >> x;
  a = x - k + 1;
  for(int i = 0;i < 2 * k - 1;i++){
    cout << a <<" ";
    a++;
  }
}