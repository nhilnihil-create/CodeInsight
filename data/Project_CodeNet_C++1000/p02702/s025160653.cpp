#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    string s; cin >> s; reverse(s.begin(), s.end());
    int i = 0, res = 0, cnt[2019]={}, mul = 1; LL ans = 0;
    cnt[0]++;

    for(char c : s) {
        res += ((c - 48) * mul);
        res %= 2019;
        ans += cnt[res];
        mul *= 10;
        mul %= 2019;  
        cnt[res]++;
    }    
    cout << ans;
}