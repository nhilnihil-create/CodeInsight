#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=a;i<b;++i)

bool is_odd(const vector<int>& v) {
    int n = v.size(), x = 0;
    for_(i,0,n) if (((n - 1) & i) == i) x ^= (v[i] & 1);
    return x;
}

int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;

    vector<int> v;
    for_(i,0,N) v.push_back(int(S[i] - '0') - 1);

    if (is_odd(v)) cout << 1 << endl;
    else if (find(v.begin(), v.end(), 1) != v.end()) cout << 0 << endl;
    else {
        for_(i,0,N) v[i] /= 2;
        if (is_odd(v)) cout << 2 << endl;
        else cout << 0 << endl;
    }
}