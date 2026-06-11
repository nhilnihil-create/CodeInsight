#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using Graph = vector<vector<ll>>;

int main(){
  long long w,h;cin>>w>>h;
  long long int x,y; cin >> x >> y;
  long double area = w/2.0 * h;
  int flag = 0;
  if (w == 2 * x && h == 2 * y)
  {
    flag = 1;
  }
  cout << fixed << setprecision(10) << area << ' ' << flag << endl;
  
}