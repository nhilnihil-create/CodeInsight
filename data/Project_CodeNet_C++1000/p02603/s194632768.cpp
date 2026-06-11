#include <bits/stdc++.h>
using namespace std;

/*
貪欲法.
株は安いときにたくさん買って, 高いときにたくさん売れば利益が最大化される.
せっかく未来が分かるのだから, 今日の株価と明日の株価を比べて,
今日の方が安かったら買える分全て買い, 明日全て売れば良い.
*/

int main() {
  long long N;
  cin >> N;
  
  long long A[85] = {0};
  for (int i = 1; i <= N; i++) cin >> A[i];
  
  long long money = 1000;
  for (int i = 1; i < N; i++) {
    long long stock = 0;
    // 今日の方が明日より安かったら買える分だけ買う
    if (A[i] < A[i+1]) stock = money / A[i];
    // 今日買ったということは明日の方が高い. 明日と今日の差額 * 今日買った株数が利益になる.
    // 今日買わなかったならstockは0なので所持金は変わらない.
    money += (A[i+1] - A[i]) * stock;
  }
  
  cout << money << endl;
}