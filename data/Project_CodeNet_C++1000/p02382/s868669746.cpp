#include <iostream>
#include <cmath>
#include <iterator>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  cin.get();

  string line;
  getline(cin, line);
  istringstream iss {line};
  vector<double> x {istream_iterator<double> {iss},
    istream_iterator<double> {}};

  getline(cin, line);
  istringstream issy {line};
  vector<double> y {istream_iterator<double> {issy},
    istream_iterator<double> {}};

  cout << fixed;

  // 1-norm, 2-norm, 3-norm
  for (double p =1; p <= 3; ++p) {
    double serr {0};
    auto xit = x.begin();
    auto yit = y.begin();
    for (; xit != x.end(); ++xit, ++yit) {
      serr += pow(abs(*xit - *yit), p);
    }
    cout << pow(serr, 1/p) << endl;
  }

  // inf-norm
  vector<double> diffs;
  auto xit = x.begin();
  auto yit = y.begin();
  for (; xit != x.end(); ++xit, ++yit)
    diffs.push_back(abs(*xit - *yit));
  double max {0};
  for (double c : diffs)
    if (c > max) max = c;
  cout << max << endl;  // print inf-norm
}
