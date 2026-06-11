#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    // Bs[i] := A が i であるような B の集まり
    vector<vector<int>> AtoB(M+1);
    for (int i = 0; i < N; ++i) {
        int A, B;
        cin >> A >> B;
        if (A > M) continue;
        AtoB[A].push_back(B);
    }

    long long result = 0;
    priority_queue<long long> que;
    for (int i = M-1; i >= 0; --i) {
        for (auto B : AtoB[M-i]) que.push(B);
        if (que.empty()) continue;
        result += que.top(); // キューの最大値を足す
        que.pop(); // キューの最大要素を削除
    }
    cout << result << endl;
}