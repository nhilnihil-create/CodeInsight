#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  int j = 0;

  int sum = 0;

  cin >> n;

  vector<int> d(n);

  rep(i,n){
    cin >> d.at(i);
  }

  for(int i=0;i<n; i++){
    j=i+1;
    while(j<n){
      sum += d.at(i)*d.at(j);
      j++;
    }
  }

  cout << sum;
}
