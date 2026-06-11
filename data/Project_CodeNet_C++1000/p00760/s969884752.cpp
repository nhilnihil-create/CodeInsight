// Millennium
#include <iostream>
using namespace std;

struct Date {
  int year, month, day;
};

void IncrementDay(Date& d) {
  d.day += 1;
  int day_of_month = 20;
  if (d.year % 3 != 0 && d.month % 2 == 0) {
    day_of_month = 19;
  }
  if (d.day > day_of_month) {
    d.day = 1;
    d.month += 1;
    if (d.month > 10) {
      d.month = 1;
      d.year += 1;
    }
  }
}

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    Date d; cin >> d.year >> d.month >> d.day;
    int ans = 0;
    while (d.year < 1000) {
      IncrementDay(d);
      ++ans;
    }
    cout << ans << endl;
  }
}