#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  double m;
  cin >> n >> m;
  vector<int> a(n);
  double summation = 0;
  for (int i = 0; i < n; i++){
    double c;
    cin >> c;
    a.at(i) = c;
    summation = summation + c; 
  }
  double border = summation / (4 * m);
  int judge = 0;
  for (int i = 0; i < n; i++){
    if (a.at(i) >= border){
      judge++;
    }
  }
  if (judge >= m){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}