/**
 * 解説の方法を試す
 * priority_queueで1個ずつ管理するのではなく、vectorで高さごとの数を管理してみる
 */

#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <functional>
#include <iterator>
#include <tuple>
#include <set>

using namespace std;

vector<int> groupby(vector<int> ss) {
  vector<int> ss_counts; // 同じ数値をひとまとめに
  int count = 0;
  int old_s = ss[0];
  for (const auto& s : ss) {
    if (s == old_s) {
      count++;
    } else {
      ss_counts.emplace_back(count);
      count = 1;
    }

    old_s = s;
  }
  ss_counts.emplace_back(count);

  return ss_counts;
}

int main() {
  int n;
  cin >> n;
  vector<int> ss(pow(2,n));

  for (int i = 0; i < pow(2,n); i++) {
    cin >> ss[i];
  }
  sort(ss.begin(), ss.end(), greater<>()); // 大きい順に並べる

  const vector<int>& ss_counts = groupby(ss);

  vector<int> slims(n+1,0); // 連結成分の数。キーはは完全二分木の木の高さ
  slims[n] = 1; // 最初は完全2分木の根。
  int slims_count = 1;

  bool result = true;

  for (const auto& ss_count : ss_counts) {
    if (slims_count < ss_count) {
      // 同じ数値を処理しきれない
      result = false;
      break;
    }

    vector<int> new_slims(slims.size(),0);
    int tmp_ss_count = ss_count;
    for (int i = slims.size()-1; tmp_ss_count > 0; i--) {
      // 今あるところから処理するため、いったん結果をnew_slimsに保存
      int current_slimis_count = min(slims[i], tmp_ss_count);
      tmp_ss_count -= current_slimis_count;
      slims[i] -= current_slimis_count;
      slims_count -= current_slimis_count;

      // 子ツリーに分割して、再度候補とする
      for (int j = 0; j < i; j++) {
        new_slims[j] += current_slimis_count;
      }
    }

    // new_slimsの結果をもとに戻す
    for (int i = new_slims.size() - 1; i >= 0; i--) {
      slims[i] += new_slims[i];
      slims_count += new_slims[i];
    }

    for (int i = slims.size() - 1; i >= 0; i--) {
      if (slims[i] == 0) {
        slims.pop_back();
      } else {
        break;
      }
    }
  }

  cout << (result ? "Yes" : "No") << endl;
}
