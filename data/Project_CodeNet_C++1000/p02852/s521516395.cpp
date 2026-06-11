#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> solve(int N, int M, const string& S)
{
    vector<int> ans;
    int x = 0;
    while (x < N) {
        int y = -1;
        for (int i = 1; i <= M && x + i <= N; ++i) {
            if (S[x + i] == '0') {
                y = x + i;
            }
        }
        if (y == -1) {
            return {};
        }
        ans.push_back(y - x);
        x = y;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;

    reverse(S.begin(), S.end());
    auto ans = solve(N, M, S);
    if (ans.empty()) {
        cout << -1 << endl;
        return 0;
    }
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
}
