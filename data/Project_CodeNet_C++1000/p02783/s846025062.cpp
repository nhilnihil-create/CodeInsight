#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int a, b;
  cin >> a >> b;
  if(a % b == 0){
    cout << a / b << "\n";
  }
  else{
    cout << a / b + 1 << "\n";
  }
}
