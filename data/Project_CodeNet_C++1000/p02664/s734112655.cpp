#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
string T;
cin >> T;
rep(i,T.size()) {
    if (T.at(i) == '?') T.at(i) = 'D';
}
cout << T << endl;

return 0;
}