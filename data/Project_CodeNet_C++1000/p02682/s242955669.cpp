#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int a, b, c, n;
  cin >> a >> b >> c >> n;
  if(a >= n){
    cout << n << "\n";
    return 0;
  }
  if(a + b >= n){
    cout << a << "\n";
    return 0;
  }
  int d = n - a - b;
  cout << a - d << "\n";
}
  