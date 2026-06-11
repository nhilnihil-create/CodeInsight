#include <iostream>
#include <iterator>
#include <array>
#include <set>
#include <algorithm>
#include <string>
#include <limits>

using namespace std;

int main()
{
  // skip the first line
  //cin.ignore(numeric_limits<streamsize>::max(), '\n');

  int n, m;
  cin >> n >> m;

  istream_iterator<int> ii {cin};
  istream_iterator<int> eos {};

  vector<int> A; // initially empty

  for (int i = 0; i < n*m; ++i) A.push_back(*(ii++));

  vector<int> B;

  copy(ii, eos, back_inserter(B));

  ostream_iterator<int> oi {cout, "\n"};
  for (int i=0; i <n; ++i)
    cout << inner_product(A.begin() + i*m, A.begin() + ((i+1)*m), B.begin(), 0) << endl;
}

