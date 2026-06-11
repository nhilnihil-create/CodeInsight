#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()

#define READ(x) (cin >> (x))

#define WRITE_N(x) (cout << (x) << endl)
#define WRITE(x) (cout << (x))

int main() {
    // get values from input
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K, C;
    string S;

    cin >> N >> K >> C >> S;

    // main procedure
    vector<int> greedy_workdays(K, -1);
    vector<int> greedy_reverse_workdays(K, -1);

    int worked_day_count = 0;
    int last_worked_day = -C;

    for (int i = 1; i <= N; ++i) {
      if (S[i-1] == 'o' && last_worked_day < (int)i - C) {
        greedy_workdays[worked_day_count++] = i;
        last_worked_day = i;

        if (worked_day_count >= K) {
          break;
        }
      }
    }

    worked_day_count = 0;
    last_worked_day = N + C + 1;

    for (int i = N; i > 0; --i) {
      if (S[i-1] == 'o' && last_worked_day > (int)i + C) {
        greedy_reverse_workdays[K - (++worked_day_count)] = i;
        last_worked_day = i;

        if (worked_day_count >= K) {
          break;
        }
      }
    }

    vector<int> ans;
    for (size_t i = 0; i < K; ++i) {
      if (greedy_workdays[i] == greedy_reverse_workdays[i] &&
          greedy_workdays[i] != -1) {
        ans.push_back(greedy_workdays[i]);
      }
    }

    // output
    for (const auto &x : ans) {
      WRITE_N(x);
    }

    return 0;
}
