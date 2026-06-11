#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;
    for(int i = 0; i < 1000; i++){
        string pass;
        if(i < 10) pass = "00" + to_string(i);
        else if(i < 100) pass = "0" + to_string(i);
        else pass = to_string(i);
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(pass[cnt] == s[j]) cnt++;
            if(cnt == 3) break;
        }
        if(cnt == 3) ans++;
    }
    cout << ans << endl;

    return 0;
}
