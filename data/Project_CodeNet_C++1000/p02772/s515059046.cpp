#include <iostream>

using namespace std;
int main(){
  int n;
  int a[100];

  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];

  bool flg = true;
  for(int i = 0; i < n; i++) {
    if(a[i]%2 == 0) {
      if((a[i]%3 != 0) && (a[i]%5 != 0)) {
        flg = false;
        break;
      }
    }
  }
  if(flg) {
    cout << "APPROVED" << endl;
  } else {
    cout << "DENIED" << endl;
  }
  return 0;
}
