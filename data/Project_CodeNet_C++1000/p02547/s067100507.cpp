#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int count = 0;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    cin >> a.at(i);
    cin >> b.at(i);
    if (a.at(i) == b.at(i)){
      count++;
      if (count == 3){
        cout << "Yes" << endl;
        break;
      }
    }
    else{
      count = 0;
    }
  }
  if (count < 3){
    cout << "No" << endl;
  }
}