#include <iostream>
#include <string>
using namespace std;
  
int main() {
    int a,b;
    cin >> a >> b;
  
    char c[3] = { ('=' - (a<b) + (a>b)) };
    c[1] = (c[0] == '=')*'=';
    cout << "a " << c << " b" << endl;
}