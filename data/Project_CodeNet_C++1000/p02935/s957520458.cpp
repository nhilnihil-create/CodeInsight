#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<double> v(N);
  
  for(int i=0; i<N ;i++){
    cin >> v.at(i);
  }
  
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
  
  vector<long long int> kaijou(N);
  kaijou.at(0) = 1;
  
  long double sum=0;
  
  for(int i=1; i<N ;i++){
    kaijou.at(i) = kaijou.at(i-1)*2;
    long double x=0;
    x = v.at(i-1)/kaijou.at(i);
    
    sum = sum + x;
  }
  
  sum = sum + v.at(N-1)/kaijou.at(N-1);
  
  cout << fixed << setprecision(10);
  cout << sum << endl;
  
}

