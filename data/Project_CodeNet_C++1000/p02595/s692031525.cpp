#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
  double n,d;
  cin >> n >> d;
  int i,j;
  vector<vector<double>> v(n,vector<double>(2));
  for(i=0;i<n;i++){
    for(j=0;j<2;j++){
      cin >> v[i][j];
    }
  }
  int cnt = 0;
  for(i=0;i<n;i++){
    if(d>=sqrt(pow(v[i][0],2)+pow(v[i][1],2))) cnt++;
  }
  cout << cnt << "\n";
  return 0;
}