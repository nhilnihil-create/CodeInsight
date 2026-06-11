#include <iostream>
using namespace std;
int main(){
  long long in;
  int count = 0;
  cin >> in;
  for(int a=1; a <= in; a++){
      for(int b = 1;b <= (in/a); b++){
          int c = in - a*b;
          if(c != 0)  count++;
      }
  }
  cout << count << endl;
}