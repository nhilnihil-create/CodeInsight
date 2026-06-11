#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define pi 3.14159265358979323846
#define ll long long
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int n;
  double m;
  cin >> n;
  if(n % 2 == 0){
    m = n / 2;
  }
  else{
    m = n / 2 + 1;
  }
  double a = m / n;
  cout << setprecision(10) << a << "\n";
}