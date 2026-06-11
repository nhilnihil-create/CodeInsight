#include<iostream>
using namespace std;
int main(){
  int a,b,c; cin >> a >> b >> c;
  int rem = a - b;
  cout <<max(0,c - rem);
}