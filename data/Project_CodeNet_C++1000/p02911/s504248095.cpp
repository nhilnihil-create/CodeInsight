#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k,q;
  cin >> n >> k >> q;
  vector<int> a(q);
  for (int i = 0;i < q;i++){
    cin >> a[i];
    a[i]--;
  }
  vector<int> c(n);
  
  for (int i = 0;i < q;i++){
    c[a[i]]++;
  }
  
  for (int i = 0;i < n;i++){
    if (k > (q - c[i])){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }
  }
}