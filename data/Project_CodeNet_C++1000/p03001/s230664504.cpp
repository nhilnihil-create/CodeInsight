#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  long long W, H, x, y;
  cin >> W >> H >> x >> y;
  cout << fixed << setprecision(12)
       << W*H/2. << " " << (x*2==W&&y*2==H?1:0) << endl;
}
