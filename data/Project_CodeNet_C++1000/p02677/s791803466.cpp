#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#define ll long long
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define FOR(i, stop) for(int i = 0; i < (stop); i++)
#define PI 3.141592653589793
using namespace std;

int main(){

  int A,B,H,M;
  cin >> A >> B >> H >> M;

  double x,y,rad;

  x = (0.5 * (H * 60 + M));
  y = (M * 6);
  rad = abs(x - y) * PI / 180.0;

  double c = A * A + B * B - 2 * A * B * cos(rad);

  cout << setprecision(14) << sqrt(c) << endl;

  return 0;
}