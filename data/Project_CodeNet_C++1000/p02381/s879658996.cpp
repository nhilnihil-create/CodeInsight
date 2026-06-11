#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
  while (true) {
    int n; cin >> n;
    if (n == 0) break;
    
    int point[n];
    double total = 0;
    for (int i = 0; i < n; i++) {
      cin >> point[i];
      total += point[i];
    }
    double avg = total / n;
    double total_p = 0;
    for (int i = 0; i < n; i++) {
      total_p += pow(point[i]-avg, 2);
    }
    cout << fixed << setprecision(6) << sqrt(total_p / n) << endl;
  }
  return 0;
}