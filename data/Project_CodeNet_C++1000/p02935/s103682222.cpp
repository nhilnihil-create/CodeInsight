#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  double sum;
  vector<double> a(n);
  for(int i = 0; i < n; i++)
    cin >> a.at(i);
  sort(a.begin(),a.end());
  sum = (a.at(0) + a.at(1))/2.0;
  for(int i = 2; i < n; i++){
    sum = (sum + a.at(i)) / 2.0;
  }
  cout << sum;
}