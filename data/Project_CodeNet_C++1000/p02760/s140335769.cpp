#include<bits/stdc++.h>
using namespace std;
int main() {
  vector<vector<int>> a(3, vector<int>(3));
  for(vector<int> &c : a) {
    for(int &d : c) {
      cin >> d;
    }
  }
  vector<vector<bool>> atob(3, vector<bool>(3, 0));
  
  int n, b; cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> b;
    for(int j = 0; j < 3; j++) {
      for(int k = 0; k < 3; k++) {
        if(a.at(j).at(k) == b) {
          atob.at(j).at(k) = 1;
        }
      }
    }
  }
  if(atob.at(0).at(0) && atob.at(0).at(1) && atob.at(0).at(2)) {
    cout << "Yes" << endl;
  }
  else if(atob.at(1).at(0) && atob.at(1).at(1) && atob.at(1).at(2)) {
    cout << "Yes" << endl;
  }
  else if(atob.at(2).at(0) && atob.at(2).at(1) && atob.at(2).at(2)) {
    cout << "Yes" << endl;
  }
  else if(atob.at(0).at(0) && atob.at(1).at(0) && atob.at(2).at(0)) {
    cout << "Yes" << endl;
  }
  else if(atob.at(0).at(1) && atob.at(1).at(1) && atob.at(2).at(1)) {
    cout << "Yes" << endl;
  }
  else if(atob.at(0).at(2) && atob.at(1).at(2) && atob.at(2).at(2)) {
    cout << "Yes" << endl;
  }
  else if(atob.at(0).at(0) && atob.at(1).at(1) && atob.at(2).at(2)) {
    cout << "Yes" << endl;
  }
  else if(atob.at(0).at(2) && atob.at(1).at(1) && atob.at(2).at(0)) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}