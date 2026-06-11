#include <iostream>

using namespace std;


#define MAX_NUM 200000

bool IsPrime(int a) {
  if (a == 2 || a == 3 || a == 5) return true;
  else if (a%2 == 0) return false;
  else if (a%3 == 0) return false;
  else if (a%5 == 0) return false;

  for(int i = 3; i < a; i+=2) {
    if(a%i == 0) return false;
  }
  return true;
}

int main(){
  int x;
  cin >> x;
  if(x%2 == 0 && x != 2) {
    x++;
  }

  while(1) {
    if(IsPrime(x) == true) {
      break;
    } else {
      x++;
    }
  }
  cout << x << endl;
  return 0;
}
