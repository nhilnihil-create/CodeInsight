#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int sum1 = 0;
  int sum2 = 0;
  
  vector<int>W(N);
  for (int i = 0; i < N; i++) {
    cin >> W.at(i);
    sum2 += W.at(i);
  }

  vector<int>count(N-1);
  for (int i = 0; i < N-1; i++) {
    sum1 += W.at(i);
    sum2 -= W.at(i);
    count.at(i) = abs(sum1-sum2);
  }
  sort(count.begin(), count.end());
  cout << count.at(0) << endl;
}
  