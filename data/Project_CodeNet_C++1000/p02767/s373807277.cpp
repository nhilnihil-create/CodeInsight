#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector <int> p(n);
  for (int i=0 ; i<n ; i++){
    cin >> p.at(i) ;
  }
  int min_dis =100000000 ;
  for (int i= 1 ; i<=100 ; i++){
    int sum_dis = 0;
    for (int j=0 ; j<n ; j++){
    sum_dis += (p.at(j)-i)*(p.at(j)-i) ;
   }
    min_dis = min ( min_dis , sum_dis) ;
  }
  cout << min_dis << endl;
}