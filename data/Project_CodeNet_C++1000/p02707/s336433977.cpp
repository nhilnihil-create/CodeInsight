#include <iostream>
#include <vector>

using namespace std;
int main(){
  int n;
  cin >> n;
  int a;
  int b[n] = {0};
  for(int i = 1; i < n; i++) {
    cin >> a;
    b[a-1]++;
  }

  for(int i = 0; i < n; i++) {
    cout << b[i] << endl;
  }
  return 0;
}
