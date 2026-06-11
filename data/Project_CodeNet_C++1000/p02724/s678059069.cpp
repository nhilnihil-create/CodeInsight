#include <bits/stdc++.h>
using namespace std;

int main() {
 int X;
 cin>>X;
 
 int apple,butter,happy;
 
 apple = X/500;
 butter = (X-500*apple)/5;
 
 happy = 1000*apple + 5*butter;
  
  cout << happy << endl;
}