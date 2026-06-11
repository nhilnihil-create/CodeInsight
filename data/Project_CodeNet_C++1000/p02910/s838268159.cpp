#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    string s; cin >> s;
    rep(i, s.size()){
        if((i+1) % 2 == 1 && (s[i] == 'R' || s[i] == 'U' || s[i] == 'D')) continue;
        else if((i+1) % 2 == 0 && (s[i] == 'L' || s[i] == 'U' || s[i] == 'D')) continue;
        else{
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
