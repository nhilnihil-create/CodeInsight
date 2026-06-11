#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  vector<int> d(N);
  for(int i = 0; i < N; i++) {
    cin >> d[i];
  }
  sort(d.begin(), d.end());
  int mid = N / 2;

  cout << d[mid] - d[mid - 1] << endl;

  return 0;
}
