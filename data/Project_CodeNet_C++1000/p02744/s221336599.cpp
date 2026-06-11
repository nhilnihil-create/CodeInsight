#include <bits/stdc++.h>
using namespace std;
 
int n;

void dfs(string s, char x) {
    if (s.length() == n) {
        cout << s << endl;
    }
    else {
        for (char c = 'a'; c <= x; c++) {
            if (c == x) dfs(s + c, (char)(x + 1));
            else dfs(s + c, x);
        }
    }
}

int main() {
    cin >> n;
    dfs("", 'a');
}