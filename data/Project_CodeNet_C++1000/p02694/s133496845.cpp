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
  ll int a = 100, b, c = 0;
  cin >> b;
  while(a < b){
    a += a / 100;
    c++;
  }
  cout << c << "\n";
  return 0;
}