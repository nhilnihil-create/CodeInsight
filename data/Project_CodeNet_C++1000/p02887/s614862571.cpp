#include <iostream>

using namespace std;

int main() {

  int n, ans = 0;
  char inp, old = '#';
  cin >> n;
  for(int i = 1;i <= n;i++){
    cin >> inp;
    if(old != inp){
      ans++;
    }
    old = inp;
  }
  cout << ans;
  return 0;
}
