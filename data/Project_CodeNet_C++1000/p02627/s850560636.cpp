using namespace std;
#include <iostream>

int main(){
  char a;
  cin >> a;
  if (toupper(a) == a) cout << 'A';
  else cout << 'a';
  return 0;      
}