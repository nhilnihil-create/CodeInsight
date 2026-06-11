#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int64_t N, A, B;
  cin >> N >> A >> B;
  cout << ((N-N%(A+B))/(A+B))*A+min((N%(A+B)),A) << endl;
}
