#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,s,n) for(int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(){
    string s;
    cin >> s;
    string last = "", now = "";
    int ans = 0;
    for(auto c : s) {
        now += c;
        if(now==last)
            continue;
        last = now;
        now = "";
        ans++;
    }
    cout << ans << endl;
    return 0;
}