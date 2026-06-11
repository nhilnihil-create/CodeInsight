#include<bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<int>> ab(n, vector<int>(2));
  vector<vector<int>> ba(n, vector<int>(2));
  
  for(int i = 0; i < n; i++) {
    int m; cin >> m;
    ab.at(i).at(0) = m;
    ba.at(i).at(1) = m;
    cin >> m;
    ab.at(i).at(1) = m;
    ba.at(i).at(0) = m;
  }
  
  
  
  if(n % 2 == 1) {
    
    
    int mids;
    
    sort(ab.begin(), ab.end());
    sort(ba.begin(), ba.end());
    
    mids = ba.at(n /2).at(0) - ab.at(n /2).at(0) +1;
    
    cout << mids << endl;
  }
  
  
  else {
    
    
    int mids;
    
    sort(ab.begin(), ab.end());
    sort(ba.begin(), ba.end());
    
    mids = ba.at(n /2 -1).at(0) + ba.at(n /2).at(0) - ab.at(n /2 -1).at(0) - ab.at(n /2).at(0) +1;
    
    cout << mids << endl;
  }
}