#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    int b;
    cin >> b;
    if(b % 2 == 0){
      if(!(b % 3 == 0 || b % 5 == 0)){
        cout << "DENIED" << endl;
        return 0;
      }
    }
  }
  cout << "APPROVED" << endl;
  return 0;
}
