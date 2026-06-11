#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<pair<string,int>>data(n);
  rep(i,n){
    cin >> data[i].first >> data[i].second;
    if(i != 0) data[i].second += data[i-1].second;
  }
  string x;
  cin >> x;
  rep(i,n){
    if(data[i].first == x){
      cout << data[n-1].second-data[i].second << endl;
      return 0;
    }
  }
}