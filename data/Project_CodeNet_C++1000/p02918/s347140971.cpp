#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    int N, K;
    string S;
    cin >> N >> K >> S;
    vector<int> T;
    T.push_back(S[0]);
    for(int i = 1; i < N; i++) {
        if(S[i - 1] != S[i]) {
            T.push_back(S[i]);
        }
    }
    for(int i = 0; i < K; i++) {
        if(T.size() > 2)
            T.erase(T.begin() + 1, T.begin() + 3);
        else if(T.size() == 2)
            T.erase(T.begin() + 1);
    }
    ans = N - 1;
    ans -= T.size() - 1;
    cout << ans << endl;
}