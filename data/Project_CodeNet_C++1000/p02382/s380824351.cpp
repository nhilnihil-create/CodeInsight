#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n; cin >> n;
  vector<double> x(n), dist(n);
  for(int i=0; i<n; i++)
    cin >> x[i];
  
  for(int i=0; i<n; i++){
    double yi; cin >> yi;
    dist[i] = abs(x[i]-yi);
  }

  printf("%0.8f\n", accumulate(dist.begin(), dist.end(),0.0));

  double sum = 0;
  for(int i=0; i<n; i++){
    sum += dist[i] * dist[i];
  }
  printf("%0.8f\n", sqrt(sum));
   
  sum = 0; 
  for(int i=0; i<n; i++){
    sum += dist[i] * dist[i] * dist[i];
  }
  printf("%0.8f\n", cbrt(sum));
  
  printf("%0.8f\n", *max_element(dist.begin(), dist.end()));

  return 0;
}