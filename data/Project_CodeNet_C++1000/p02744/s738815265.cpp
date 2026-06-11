#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, mod = 1e9 + 7;

int n, p[N];
vector<string> res;

int get(int a) {
    return p[a] = (a == p[a] ? a : get(p[a]));
}

void join(int a, int b) {
    a = get(a), b = get(b);
    p[b] = a;
}

void init() {
    for(int i = 0; i < n; i++) p[i] = i;
}
string s;
void solve(int i, char c, int vis, bool bo) {
    if(vis == (1 << n) - 1) {
        res.push_back(s);
        return;
    }
    if(i == n) solve(0, c + 1, vis, 0);
    else if((vis >> i) & 1) solve(i + 1, c, vis, bo);
    else {
        if(!bo) {
            s[i] = c;
            solve(i + 1, c, vis ^ (1 << i), 1);
        }
        else {
            s[i] = c;
            solve(i + 1, c, vis ^ (1 << i), bo);
            solve(i + 1, c, vis, bo);
        }
    }
}

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc = 1; 
   // scanf("%d", &tc);
    while(tc--) {
        cin >> n;
        for(int i = 0; i < n; i++) p[i] = i;
        s.resize(n);
        solve(0, 'a', 0, 0);
        sort(res.begin(), res.end());
        for(auto x : res) printf("%s\n", x.c_str());
    }    
    return 0;
}