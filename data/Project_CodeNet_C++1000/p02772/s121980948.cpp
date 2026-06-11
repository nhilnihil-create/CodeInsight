#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<int> x(n);
  for(int i=0;i<n;i++){
    cin >> x[i];
    if(x[i]%2==0) {
      if(x[i]%3!=0&&x[i]%5!=0){
        cout << "DENIED" << endl;
        return 0;
      }
      }
  }
  cout << "APPROVED" << endl;
  return 0;
}