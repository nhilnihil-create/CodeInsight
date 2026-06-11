#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<iomanip>
#define pi 3.14159265358979323846
#define int long long
#define elif else if
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int gcd(int x, int y){
  if(y == 0) {
    return x;
  } else{
    return gcd(y, x % y);
  }
}
signed main(){
  int a, b;
  cin >> a >> b;
  int c = gcd(a, b);
  cout << a * b / c << "\n";
}