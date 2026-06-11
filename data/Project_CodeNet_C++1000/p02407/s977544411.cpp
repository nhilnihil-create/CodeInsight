#include <iostream>
using namespace std;
int main(){
  int n,s;
  cin >> n;
  int num[n];
  for (int i = 0; i < n; i++) {
    cin >> s;
    num[i] = s;
  }
  for (int i = n - 1; i >= 0; i--){
    cout << num[i];
    if (i > 0)cout << " ";
    else if (i == 0)cout << endl;
  }
  return 0;
}