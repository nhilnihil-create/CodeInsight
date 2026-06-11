#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define abdelrahman010 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
const int N = 1e5 + 5;
string s;
vector<string> v;
int main() {
    abdelrahman010
    cin >> s;
    string tmp = "";
    for(int i = 0;i < s.size();i++) {
        tmp += s[i];
        if(v.empty() || tmp != v.back()) {
            v.push_back(tmp);
            tmp = "";
        }
    }
    cout << v.size();
    return 0;
}