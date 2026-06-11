#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  long long int a, b;
  cin >> a >> b;
  if(a == 1 || b == 1){
    cout << "1\n";
    return 0;
  }
  long long int c = a * b;
  if(c % 2 == 0){
    cout << c / 2 << "\n";
    return 0;
  }
  cout << c / 2 + 1 << "\n";
}
