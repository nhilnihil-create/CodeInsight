#include <bits/stdc++.h>
using namespace std;

const int MAX = 1100000;
vector<long long> cnt; // cnt[n] := n! が 2 で何回割れるか
void pre() {
    cnt.assign(MAX, 0);
    for (int i = 1; i < MAX; ++i) {
        int j = i;
        int add = 0;
        while (j % 2 == 0) ++add, j /= 2;
        cnt[i] = cnt[i-1] + add;
    }
}

int solve(const string &S) {
    pre();
    vector<int> a;
    for (int i = 0; i + 1 < S.size(); ++i) {
        int x = S[i] - '0';
        int y = S[i+1] - '0';
        a.push_back(abs(x - y));
    }
    long long parity = 0;
    for (int i = 0; i < a.size(); ++i) {
        long long ex = cnt[a.size()-1] - cnt[i] - cnt[a.size()-i-1];
        if (ex > 0) continue;
        parity += a[i];
    }

    if (parity & 1) return 1;
    else {
        bool exist_one = false;
        for (int i = 0; i < a.size(); ++i) if (a[i] == 1) exist_one = true;
        if (exist_one) return 0;
        else {
            parity = 0;
            for (int i = 0; i < a.size(); ++i) {
                long long ex = cnt[a.size()-1] - cnt[i] - cnt[a.size()-i-1];
                if (ex > 0) continue;
                parity += a[i] / 2;
            }
            if (parity & 1) return 2;
            else return 0;
        }
    }
  }

int main() {
    int N;
    string S;
    cin >> N >> S;
    cout << solve(S) << endl;
}