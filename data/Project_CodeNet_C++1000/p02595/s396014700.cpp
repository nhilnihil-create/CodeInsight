#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int N, D;
  cin >> N >> D;
  
  int num_points = 0;
  
  long x, y;
  for (int i = 0; i < N; i++){
    cin >> x >> y;
    double edge = sqrt(x*x + y*y);
    if (edge <= D) num_points++;
  }
  
  cout << num_points;
  
  return 0;
}