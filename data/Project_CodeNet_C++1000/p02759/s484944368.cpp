#include<iostream>
#include<string>
using namespace std;
int main(){
  int n, m;
  cin >> n;
  if(n % 2 == 1){
    m = (n + 1) / 2;
    cout << m << "\n";
    return 0;
  }
  m = n / 2;
  cout << m << "\n";
}