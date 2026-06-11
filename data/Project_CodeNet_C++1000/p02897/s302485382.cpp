#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  if(n%2==0) cout << 0.5 << endl;
  else{
    double n2 = n;
    cout << (n2+1)/2/n2 << endl;
  }
}
