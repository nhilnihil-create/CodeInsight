#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int width, height;
  cin >> width >> height;
  int s = width * height;
  int l = (width + height) * 2;
  cout << s << " " << l << endl;
}