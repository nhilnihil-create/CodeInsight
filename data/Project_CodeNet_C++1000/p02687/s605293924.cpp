#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(std::string S) {
    if (S == "ABC") cout << "ARC" << endl;
    if (S == "ARC") cout << "ABC" << endl;
}

int main() {
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
