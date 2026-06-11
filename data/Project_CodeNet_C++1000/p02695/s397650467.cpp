#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;

int N, M, Q, S;
/*
int bit_search(vector<int> a, vector<int> b, vector<int> c, vector<int> d) {
    int sum = 0;
    for (int bit = 0; bit < (1 << M); ++bit) {
        if (__builtin_popcount(bit) == N) {
            int cnt = 0;
            for (int i = 0; i < N; i++) {
                if (bit & (1 << i)) { 
                    cnt++;
                    for (int j = 0; j < Q; j++) {
                        if (cnt == a.at(j)) {
                            int tmp = 0;
                            for (int k = 0; k < N; k++) {
                                if (bit & (1 << k)) tmp++;
                                if (tmp == b.at(j)) {
                                    if ((k - i) == c.at(j)) sum += d.at(j);
                                    else break;
                                }
                            }
                        }
                    }
                } else continue;
            }
        } else continue;
    }
    return sum;
}
*/

int dfs(int cnt, int num, vector<int> K, vector<int> a, vector<int> b, vector<int> c, vector<int> d) {
    int sum = 0;
    if (cnt < S) {
        if (num < N && (cnt - num) < M - 1) {
            cnt++;
            sum = max(sum, dfs(cnt, num, K, a, b, c, d));
            num++;
            K.at(cnt - 1) = 1;
            sum = max(sum, dfs(cnt, num, K, a, b, c, d));
        } else if (num >= N) {
            cnt++;
            sum = max(sum, dfs(cnt, num, K, a, b, c, d));
        } else if ((cnt - num) >= M - 1) {
            cnt++;
            num++;
            K.at(cnt - 1) = 1;
            sum = max(sum, dfs(cnt, num, K, a, b, c, d));
        }
    } else {
        vector<int> Y;
        int j = 1;
        for (int i = 0; i < S; i++) {
            if (K.at(i) == 1) Y.push_back(j);
            else j++;
        }
        for (int i = 0; i < Q; i++) {
            if (Y.at(b.at(i) - 1) - Y.at(a.at(i) - 1) == c.at(i)) sum += d.at(i);
        }
    }
    return sum;
}

int main(){
    cin >> N >> M >> Q;
    S = N + M - 1;
    vector<int> a(Q), b(Q), c(Q), d(Q);
    for (int i = 0; i < Q; i++) {
        cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);
        //a.at(i)--;
        //b.at(i)--;
    }

    vector<int> K(S, 0);
    //vector<int> dp(N, 0);
    //int sum = bit_search(a, b, c, d);
    //cout << sum << endl;

    int sum = dfs(0, 0, K, a, b, c, d);
    cout << sum << endl;

    return 0;
}
