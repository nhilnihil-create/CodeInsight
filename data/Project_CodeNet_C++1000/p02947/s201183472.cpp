#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    int N; cin >> N;
    unordered_map<string, long long int> Map(N);
    vector<string> S(N, "");
    for (int i = 0; i < N; ++i) cin >> S[i];
    long long int cnt = 0;
    for (int i = 0; i < N; ++i) {
        sort(S[i].begin(), S[i].end());
        Map[S[i]]++;
        cnt += Map[S[i]] - 1;
    }
    cout << cnt << endl;
}
