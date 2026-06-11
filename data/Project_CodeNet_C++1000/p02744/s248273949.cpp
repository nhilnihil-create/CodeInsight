#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void dfs(vector<char> &v, char to, int n) {
    if (v.size() == n) {
        for (auto e : v) printf("%c", e);
        printf("\n");
        return;
    }
    for (char c = 'a'; c <= to; c++) {
        v.push_back(c);
        if (c == to) dfs(v, to + 1, n);
        else dfs(v, to, n);
        v.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    vector<char> v;
    v.push_back('a');
    dfs(v, 'b', n);
}
