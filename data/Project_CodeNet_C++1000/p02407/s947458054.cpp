#include <iostream>
using namespace std;

int main() {
  int a[105],c,b;
  cin >> c;
  for (int i = c;i > 0;i--){
    cin >> a[i];
  }
  for (int i = c;i > 0;i--){
    int b =c - i + 1;
    cout << a[b] ;
    if (b < c){
      cout << " ";
    }
  }
  cout<<endl;
  return 0;
}
