#include<iostream>
#include<string>
using namespace std;
int main(){
  int a, b , c, n;
  cin >> a >> b >> c;
  n = c / a + 1;
  for(int i = 1; i < n; i++){
    int s = 0;
    s = a * i;
    if(b <= s){
      cout <<"OK\n";
      return 0;
    }
  }
  cout << "NG\n";
}