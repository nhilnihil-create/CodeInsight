#include<iostream>
using namespace std;

int main(){

  int width = 0;
  int height = 0;
  
  cin >> width >> height;

  int m2 = width * height;
  int syu = (width + height) * 2;

  cout << m2 << " " << syu << endl;

  return 0;
}