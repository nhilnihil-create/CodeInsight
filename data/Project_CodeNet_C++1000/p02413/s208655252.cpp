#include <iostream>
using namespace std;


int main(){

  int r,c; cin >> r >> c;
  int row[r]={},col[c]={};
  int sum;
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      int t;
      cin >> t;
      row[i] += t;
      col[j] += t;
      sum += t;
      cout << t << " ";
    }
    cout << row[i] << endl;
  }
  for(int j=0; j<c; j++){
    cout << col[j] << " ";
  }
  cout << sum << endl;

}