#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rng(i,a,b) for(int i = (a); i < (b); ++i)

int N;

bool parity(int n, int r) {
    return n == (r | (n - r));
}

vector<int> getPositions(const string& str, const string& find_word) {
    vector<int> res;
    string::size_type pos = str.find(find_word);
    while (pos != string::npos) {
      res.push_back(pos);
      pos = str.find(find_word, pos + find_word.length());
    }
    return res;
}

int calc(vector<int> poss) {
    int res = 0;
    for (auto pos : poss) {
        res ^= parity(N-1, pos);
    }
    return res;
}

int main() {
    cin >> N;
    string s; cin >> s;
    vector<int> twos = getPositions(s, "2");
    vector<int> threes = getPositions(s, "3");
    if (!twos.empty()) {
        cout << calc(twos) << endl;
    } else if (!threes.empty()) {
        cout << 2*calc(threes) << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
