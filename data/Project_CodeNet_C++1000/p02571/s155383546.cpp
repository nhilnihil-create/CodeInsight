#include <bits/stdc++.h>

using namespace std;

int main() {

    string s, t;    
    cin >> s >> t;

    int cnt, ans = 1000;
    for(int i = 0; i < s.length()-t.length()+1; i++) {
        cnt = 0;
        for(int j = 0; j < t.length(); j++) {
            if(s.at(i+j) != t.at(j)) cnt++;
        }

        ans = min(cnt, ans);
    }

    cout << ans << endl;

    return 0;
}

int min(int a, int b) {
    if(a<b) return a;
    else return b;
}