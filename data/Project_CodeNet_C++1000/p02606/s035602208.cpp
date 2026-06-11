#include<iostream>
#include<vector>
using namespace std;

int main()
{
  int L, R, d;
  cin >> L >> R >> d;

  vector<int> v;
  for (int i=L; i<=R; i++)
  {
    if (i % d == 0) {
      v.push_back(i);
    }
  }
  cout << v.size() << endl;
  return 0;
}