#include <bits/stdc++.h>
using namespace std;

vector<int> lol = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
int N;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> N;
  cout << lol[N - 1] << "\n";
}