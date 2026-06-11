#include<iostream>
using namespace std;

int main() {
  char c;
  cin>>c;
  cout<<('A' <= c && c <= 'Z' ? 'A' : 'a')<<endl;
  return 0;
}
