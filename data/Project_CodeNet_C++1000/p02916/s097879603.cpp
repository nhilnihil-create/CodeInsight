#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;

  cin >> n;

  int sum = 0;

  int tmp;

  vector<int> a(n+1);
  vector<int> b(n);
  vector<int> c(n-1);

  rep(i,n){
    cin >> a.at(i);
  }


  rep(i,n){
    cin >> b.at(i);
  }

  rep(i,n-1){
    cin >> c.at(i);
  }

  int j = 0;

  rep(i,n){
    // tmp;
    if(a.at(i)+1 == a.at(i+1)){
      sum += c.at(a.at(i)-1);
    }
    sum += b.at(a.at(i) - 1);
    }

    cout << sum;
}
