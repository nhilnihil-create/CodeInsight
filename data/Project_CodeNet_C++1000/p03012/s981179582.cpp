#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  cin >> N;

  int left = 0;
  int right = 0;
  vector<int> W(N);

  for (int i = 0; i < N; i++)
  {
    cin >> W.at(i);
    if (i == 0) left += W.at(i);
    else
    {
      right += W.at(i);
    }
  }

  int min = abs(left - right);
  for (int i = 1; i < N; i++)
  {
    left += W.at(i);
    right -= W.at(i);

    if (abs(left - right) < min)
    {
      min = abs(left - right);
    }
  }
  cout << min << endl;
}