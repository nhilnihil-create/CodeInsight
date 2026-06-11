#include<iostream>
using namespace std;

int main(){
  int k, a, b;
  cin >> k >> a >> b;
	
  if (a % k == 0 || b % k == 0){
    cout << "OK" << endl;
    return 0;
  }
  
  int x;
  x = a - (a % k) + k;

  if (b >= x){
    cout << "OK" << endl;
  } else{
    cout << "NG" << endl;
  }
  return 0;
}
