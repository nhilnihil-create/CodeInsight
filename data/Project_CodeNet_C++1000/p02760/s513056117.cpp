#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
  vector<vector<int>> a(3, vector<int>(3));
  vector<vector<bool>> ans(3, vector<bool>(3, false));
  
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      cin >> a.at(i).at(j);
    }
  }
  
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int b;
    cin >> b;
    
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        if(b == a.at(i).at(j)) ans.at(i).at(j) = true;
      }
    }
  }
  
  if(ans.at(0).at(0) == true && ans.at(0).at(1) == true && ans.at(0).at(2) == true) cout << "Yes" << endl;
  else if(ans.at(1).at(0) == true && ans.at(1).at(1) == true && ans.at(1).at(2) == true) cout << "Yes" << endl;
  else if(ans.at(2).at(0) == true && ans.at(2).at(1) == true && ans.at(2).at(2) == true) cout << "Yes" << endl;
  else if(ans.at(0).at(0) == true && ans.at(1).at(0) == true && ans.at(2).at(0) == true) cout << "Yes" << endl;
  else if(ans.at(0).at(1) == true && ans.at(1).at(1) == true && ans.at(2).at(1) == true) cout << "Yes" << endl;
  else if(ans.at(0).at(2) == true && ans.at(1).at(2) == true && ans.at(2).at(2) == true) cout << "Yes" << endl;
  else if(ans.at(0).at(0) == true && ans.at(1).at(1) == true && ans.at(2).at(2) == true) cout << "Yes" << endl;
  else if(ans.at(0).at(2) == true && ans.at(1).at(1) == true && ans.at(2).at(0) == true) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  
  
}