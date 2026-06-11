#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const vector<int> s={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

int main(){
  int K;
  cin >> K;
  --K;
  cout << s[K] << endl;
}