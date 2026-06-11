#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < n;i++)
typedef long long ll;
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  
  vector<int> a(m);
  rep(i, m){
    cin >> a[i];
  }

  int sum;
  sum = accumulate(a.begin(), a.end(), 0);
  int temp = n - sum;
  if (temp == 0){
    cout << 0 << endl;
  }else if(temp < 0){
    cout << -1 << endl;
  }else{
    cout << temp << endl;
  }
  
}