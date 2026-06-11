#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
  int n,m;
  string s;
  cin >> n >> m;
  vector<int> v(n);
  int sum = 0;
  rep(i,n){
    cin >> v[i];
    sum += v[i];
  }
  int can = 0;
  rep(i,n){
    if (v[i] >= (sum + 4*m-1)/(4*m) ){
      can++;
      //cout << v[i] << endl;
    }

  }
  if (can >= m) cout << "Yes" << endl;
  else cout << "No" << endl;
}
