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
  ll int n, k;
  cin >> n >> k;
  
  ll int a = n % k;
  if(a == 0){
    cout << "0\n";
    return 0;
  }
  ll int b = a - k;
  b = b * (-1);
  if(a < b){
    cout << a << "\n";
    return 0;
  }
  cout << b << "\n";
}
  