#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  int a,b,tmp,sqr,sum=0;
  cin >> a >> b;
  vector<vector<int>> data(a, vector<int>(b));
  rep(i,a){
    rep(j,b){
      cin >> data.at(i).at(j);
    }
  }
  for(int i = 0;i<a-1;i++){
    for(int j = i+1;j<a;j++){
      tmp = 0;
    for(int h = 0;h<b;h++){
    tmp += (data.at(i).at(h)-data.at(j).at(h))*(data.at(i).at(h)-data.at(j).at(h));
    }
     sqr = sqrt(tmp);
    if(tmp==sqr*sqr)sum++;
    }
  }
  cout << sum;
}