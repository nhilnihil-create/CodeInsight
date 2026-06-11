#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  int a, b; cin >> a >> b;
  
  cout << a/b << ' ' << a%b << ' ' << fixed << setprecision(7) << (double)a/double(b) << endl;
  return 0;
}