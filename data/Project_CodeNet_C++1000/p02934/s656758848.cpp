#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i=0 ; i<n ; i++)
    cin >> a.at(i);
  
  double sum = 0, plus;
  for (int i=0 ; i<n ; i++){
    plus = 1;
    plus /= a.at(i);
    sum += plus;
  }
  
  sum = 1/sum;
  
  cout << fixed << setprecision(10) << sum << endl;
}