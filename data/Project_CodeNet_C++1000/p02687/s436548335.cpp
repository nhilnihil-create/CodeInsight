#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define reps(i,s,n) for (int i = (s); i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {

    string S;
    cin >> S;
    string ans = (S == "ABC")?"ARC":"ABC";
    cout << ans << endl;

    return 0;
}
    