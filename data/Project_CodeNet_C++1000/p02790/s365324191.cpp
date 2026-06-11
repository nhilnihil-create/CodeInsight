#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<iomanip>
#include<cmath>
#define pi 3.14159265358979323846
#define mod 1000000007
#define int long long
#define elif else if
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
signed main(){
  int a, b;
  cin >> a >> b;
  
  if(b > a){
    int d = b;
    b = a;
    a = d;
  }
  //cout << a << " "<< b << "\n";
  int c = b,e = 1;
  rep(i, 0, a - 1){
    e = e * 10;
    c += b * e;
  }
  cout << c << "\n";
}
      