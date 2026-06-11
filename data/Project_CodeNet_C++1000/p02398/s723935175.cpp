#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  int a, b, c, cnt;
  cin >> a >> b >> c;

  for(int i = a ; i < b+1 ; i++){
    if(c % i == 0){
      cnt++;
    }
  }
  cout << cnt << endl;

  return 0;
}