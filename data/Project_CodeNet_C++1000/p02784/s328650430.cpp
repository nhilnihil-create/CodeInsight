#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int h,n;
  cin >> h >> n;
  vector<int> A(n);
  int sum = 0;
  for (int i = 0; i < n; i++){
    cin >> A[i];
    sum += A[i];
  }
  if (h <= sum){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}