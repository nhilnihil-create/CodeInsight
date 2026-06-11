#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<string> vec(N);

  for (int i = 0; i < N; i++)
    cin >> vec.at(i);

  sort(vec.begin(), vec.end());

  vec.erase(unique(vec.begin(), vec.end()), vec.end());

  cout << vec.size() << endl;
}
