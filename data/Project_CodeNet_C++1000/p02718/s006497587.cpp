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
  int n, m, sm = 0, c = 0;
  cin >> n >> m;
  int a[n];
  rep(i, 0, n){
    cin >> a[i];
    sm += a[i];
  }
  double s = (sm + 4 * m - 1) / (4 * m);
  
  rep(i, 0, n){
    if(a[i] >= s){
      c++;
    }
  }
  if(c >= m){
    cout << "Yes\n";
    return 0;
  }
  cout << "No\n";
}