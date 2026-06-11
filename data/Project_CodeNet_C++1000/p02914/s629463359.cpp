/**
 * 降参。
 * 解説の方法を試す
 *
 * xorが0のビットのみ、1,1に分けると結果が増えることは理解した。
 *
 * 0ビットの最大化を求めるのに行標準形を使えるのは、
 * 1.貪欲でいい理由は、同じビットが立っているデータがあった場合、後の候補に今の選択(A)を取り消して他の候補を選んだ場合(A+B)、というデータが残るため
 * 2.その選択が可能である理由は、全行のxorはどう計算しようが、各行が高々1回xorされるだけで算出できるため。
 *
 *   例: 行標準形計算後
 *
 *     1 0 1 0 A
 *     0 1 1 0 A+B
 *     0 0 1 0 A+C
 *     0 0 0 1 A+B+C+D
 *
 *     全行のxor = A+A+B+A+C+A+B+C+D = D (xorなので、2回足すと0に戻る)
 *
 * 計算量は、
 *   その桁の1が立っているデータを探す O(N)
 *   他のデータをxorして、その桁を0にする O(N)
 * を桁数(=60ビット)繰り返せばいいので、全体でO(N)
 *
 */
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long int> as(n);
  long long int as_xor = 0;

  for (int i = 0; i < n; i++) {
    cin >> as[i];
    as_xor ^= as[i]; // 全Aのxorを出しておいて
  }

  // 0の部分を抽出する
  long long int mask = ~as_xor;
  for (int i = 0; i < n; i++) {
    as[i] &= mask;
  }

  long long int zero_xor = 0;

  for (long long int i = (1ll<<60); i > 0; i>>=1) { //上のビットから順に処理していき
    auto const a_ite = find_if(as.begin(), as.end(), [i](const auto& a){ return (a&i) != 0; });

    if (a_ite != as.end()) { //今のビットが1のデータが見つかったら
      const auto a = *a_ite;

      if ((zero_xor&i) == 0) { // まだビットが立っていない場合は追加 (貪欲)
        zero_xor ^= a;
      }

      for (auto& a2 : as) { //行標準形にするため、xorしてこの桁を0にしていく
        if ((a2&i) != 0) {
          a2 ^= a;
        }
      }

      remove(as.begin(), as.end(), 0); // 高速化のため0のデータは消しておく...効果あるか？
    }
  }

  long long int result = as_xor + 2 * zero_xor; // 結果は、ビットが1の部分(as_xor)と、ビットが0だった部分(zero_xor, 2個に分けるので足して2倍になる)

  cout << result << endl;
}
