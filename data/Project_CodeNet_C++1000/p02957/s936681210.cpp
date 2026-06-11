#include<iostream>
using namespace std;
int main(){
  long long a, b;
  cin >> a >> b;
  if((a + b) % 2 == 1){
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  cout << (a + b) / 2 << "\n";
}