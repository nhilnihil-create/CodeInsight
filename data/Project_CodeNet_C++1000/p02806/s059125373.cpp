#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e17;
const ll MOD = 1e9+7;

int main() {
    // input, ready
    int N;
    vector<string> vec_s;
    vector<int> vec_t;
    string X;
    cin >> N;
    vec_s.resize(N);
    vec_t.resize(N);
    for (int i=0; i < N; i++) cin >> vec_s[i] >> vec_t[i];
    cin >> X;

    // resolve;
    int idx=0;
    for (auto s: vec_s) {
        if (s == X) break;
        idx++; 
    }

    // output
    auto beg = next(vec_t.begin(), idx+1);
    cout << accumulate(beg, vec_t.end(), 0) << endl;

    return 0;
}