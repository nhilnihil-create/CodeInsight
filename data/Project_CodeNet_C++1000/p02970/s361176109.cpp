#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
int main() {
  int n,d;
  cin >> n >> d;
  int range = 2*d+1;
  int i=0;
  while(n>0){
    n -= range;
    i++;
  }
  cout << i << endl;
}