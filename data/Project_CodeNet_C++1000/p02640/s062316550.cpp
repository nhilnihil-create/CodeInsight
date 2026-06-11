#include<iostream>
using namespace std;

int main() {
  int X,Y;
  cin>>X>>Y;
  int t = (X*4 - Y)/2;
  int k = (Y - X*2)/2;
  cout<<(Y%2 == 0 && t>=0 && k>=0 ? "Yes" : "No")<<endl;
  return 0;
}
