#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using str = string;
using ll = long long;
using vi = vector<int>;
using vii = vector<vi>;

int main() {
    str S;
    cin >> S;
    if(S[2] == S[3] && S[4] == S[5]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}