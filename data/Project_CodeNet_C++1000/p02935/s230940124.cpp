#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<double> v(N);

  for (int i = 0; i < N; i++)
    cin >> v.at(i);

  while (v.size() != 1)
  {
    // 小さい順に
    sort(v.begin(), v.end());

    // (1番小さい具材 + 2番目に小さい具材) / 2 を先頭に追加
    v.insert(v.begin(), (v.at(0) + v.at(1)) / 2);

    // 鍋に入れた具材を削除
    v.erase(v.begin() + 1);
    v.erase(v.begin() + 1);
  }

  cout << fixed << setprecision(5) << v.at(0) << endl;
}
