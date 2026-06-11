#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<vector<pair<int, int>>>shougens(N);
    for (int i=0; i<N; i++) {
        int shougen_count;
        cin >> shougen_count;
        shougens[i].resize(shougen_count);
        for (int j=0; j<shougen_count; j++) {
            int x, y;
            cin >> x >> y;
            shougens[i][j] = make_pair(x, y);
        }
    }

    int max_count = 0;
    // 正直者の数と組み合わせを仮定して、矛盾していないかどうかをチェックしていく
    // 矛盾しているケースが生まれた場合は、その仮定が成り立たないので棄却する
    // 全部うまくいくとした場合にmax_countと比較して数が多かったらそちらを採用する
    for (int bit=1; bit < (1 << N); bit++) {
        bool umakuiku = true;
        for (int i=0; i<N; i++) {
            bool syouziki = false;
            if (bit & (1<<i)) {
                syouziki = true;
            }

            for (int j=0; j<shougens[i].size();j++) {
                // この発言をした人が正直者とするならば、対象も正直になるはず
                pair<int, int> syougen = shougens[i][j];
                int x = syougen.first;
                int y = syougen.second;
                if (syouziki && y == 1) {
                    if (!(bit & (1 << (x -1)))) {
                        umakuiku = false;
                        break;
                    }
                } else if (syouziki && y == 0) {
                    if ((bit & (1 << (x -1)))) {
                        umakuiku = false;
                        break;
                    }

                }
            }
        }

        if (umakuiku) {
            int count = __builtin_popcount(bit);
            if (count > max_count) {
                max_count = count;
            }
        }
    }

    cout << max_count << endl;
    return 0;
}