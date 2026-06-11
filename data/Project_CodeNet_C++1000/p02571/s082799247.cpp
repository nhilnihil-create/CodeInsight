#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int i, n, m, j;
    string s, t;
    cin >> s >> t;
    int best = INT_MAX;
    n = s.length();
    m = t.length();
    for(i = 0; i < n - m + 1; i++){
        int res = 0;
        for(j = 0; j < m; j++){
            if(s[i + j] != t[j])
                res++;
        }
        best = min(best, res);
    }
    cout << best << endl;
}