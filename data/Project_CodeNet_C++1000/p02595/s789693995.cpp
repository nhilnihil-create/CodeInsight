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
  ll n, d, sm = 0;
  cin >> n >> d;
  d = d * d;
  ll int x[n], y[n], z[n];
  rep(i, 0, n){
    cin >> x[i] >> y[i];
    x[i] = x[i] * x[i];
    y[i] = y[i] * y[i];
    z[i] = x[i] + y[i];
    if(z[i] <= d){
      sm++;
    }
  }
  cout << sm << "\n";
}