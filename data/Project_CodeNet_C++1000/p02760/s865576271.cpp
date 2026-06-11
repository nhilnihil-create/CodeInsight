#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<vector<int>> A(3,vector<int> (3));
  for(int i=0;i<3;i++) for(int j=0;j<3;j++) cin >> A.at(i).at(j);
  int N,b;
  cin >> N;

  for(int i=0;i<N;i++){
    cin >> b;
    for(int j=0;j<3;j++) for(int k=0;k<3;k++) if(b==A.at(j).at(k)) A.at(j).at(k) = 0;    
  }

  int sum_cross = A.at(0).at(0) + A.at(1).at(1) + A.at(2).at(2);
  int sum_cross_rev = A.at(0).at(2) + A.at(1).at(1) + A.at(2).at(0);
  for(int i=0;i<3;i++){
    int sum_row = 0;
    int sum_col = 0;
    for(int j=0;j<3;j++){
//      cout << A.at(i).at(j) << endl;
      sum_row += A.at(i).at(j);
      sum_col += A.at(j).at(i);
    }
//    cout << sum_row << " : " << sum_col << " : " << sum_cross << endl;
    if(sum_row == 0 || sum_col == 0 || sum_cross == 0 || sum_cross_rev == 0){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}