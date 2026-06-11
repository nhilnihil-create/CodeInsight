#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int a;
  cin >> a;
  if(a % 2 == 0){
    cout << a / 2 << "\n";
  }
  else{
    cout << a / 2 + 1 << "\n";
  }
}
