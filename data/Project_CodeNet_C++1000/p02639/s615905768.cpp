using namespace std;
#include <iostream>

int main(){
  int n;
  int count = 1;
  while (cin >> n){
    if (n == 0) {
      cout << count;
      return 0;
    }
    count++;
  }
}