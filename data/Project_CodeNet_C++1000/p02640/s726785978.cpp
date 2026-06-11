#include<iostream>
using namespace std;

int main() {
  int X,Y;
  cin>>X>>Y;
  int t2 = Y - X*2;
  int k2 = X*4 - Y;
  cout<<(t2>=0 && t2%2 == 0 && k2>=0 && k2%2 == 0 ? "Yes" : "No")<<endl;
  return 0;
}
