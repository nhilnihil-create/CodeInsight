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
  int n, m;
  cin >> n >> m;
  vector<int> h(n, 0);
  rep(i, 0, n){
    cin >> h[i];
  }
  vector<vector<int>> v(n);
  rep(i, 0, m){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  vector<int> x(n, 0);
  int good = 0;
  rep(i, 0, n){
    for(int j: v[i]){
      if(h[i] <= h[j]){
        x[i]++;
        break;
      }
    }
  }
  rep(i, 0, n){
    if(x[i] == 0){
      good++;
    }
  }
  cout << good << "\n";
}