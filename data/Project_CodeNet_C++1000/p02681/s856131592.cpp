#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

const string YES = "Yes";
const string NO = "No";

void solve(std::string S, std::string T) {
    if (S.size() + 1 != T.size()) {
        cout << NO << endl;
    } if (T.substr(0, S.size()) == S) {
        cout << YES << endl;
    } else {
        cout << NO << endl;
    }
    
}

int main() {
    std::string S;
    std::cin >> S;
    std::string T;
    std::cin >> T;
    solve(S, T);
    return 0;
}
