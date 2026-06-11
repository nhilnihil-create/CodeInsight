#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int y, m, d, t;
  for (int i = 0; i < n; ++i){
    t = 196470;
    cin >> y >> m >> d;
    t -= 195*(y-1) + 5*((y-1)/3);
    if (y%3) t -= 20*(m-1) - (m-1)/2;
    else t -= 20*(m-1);
    t -= d-1;
    cout << t << endl;
  }
}