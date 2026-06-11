#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long MOD = 1e9+7;
int MAX_INT = 1e9;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long N, A, B;
  cin >> N >> A >> B;

  cout << ((B - A) % 2 == 0 ? (B - A) / 2 : min(A - 1, N - B) + 1 + ((B - A - 1) / 2)) << endl;

    return 0;
}
