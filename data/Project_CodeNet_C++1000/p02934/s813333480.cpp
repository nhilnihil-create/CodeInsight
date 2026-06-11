#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>

const ll INF = pow(10, 9) + 7;

int main() {
  int n;
  cin >> n;
  double a=0,b;
  rep(i,n){
    double x;
    cin >>x;
    a += 1/x;
  }
  cout << 1/a << endl;
}