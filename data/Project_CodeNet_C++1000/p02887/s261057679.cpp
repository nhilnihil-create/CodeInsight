#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n;cin >> n;
    string s; cin >> s;
    char temp = s[0];
    vector<char> str;
    str.push_back(s[0]);
    for(int i = 1; i < n; i++){
        if(temp == s[i]) continue;
        temp = s[i];
        str.push_back(s[i]);
    }
    cout << str.size() << endl;
    return 0;
}
