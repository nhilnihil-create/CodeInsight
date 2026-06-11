#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
  int n, d;
  cin >> n >> d;
  vector<vector<int>> x(n, vector<int>(d));
  for (int i=0 ; i<n ; i++){
    for (int j=0 ; j<d ; j++)
      cin >> x.at(i).at(j);
  }
  
  int d2, ans = 0;
  double d1;
  for (int i=0 ; i<n-1 ; i++){
    for (int j=i+1 ; j<n ; j++){
      d2 = 0;
      for (int k=0 ; k<d ; k++){
        d2 += (x.at(i).at(k)-x.at(j).at(k))*(x.at(i).at(k)-x.at(j).at(k));
      }
      d1 = sqrt(d2);
      if (d1 == floor(d1))
        ans++;
    }
  }
  
  cout << ans << endl;
}