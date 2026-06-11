#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    ll ans = 0;
    map<int, ll> freq;
    for(int i = 11; i <= n; i++){
        if(i % 10 == 0) continue;
        string s = to_string(i);
        int x = (s[0] - '0') * 10 + i % 10;
        freq[x]++;
    }
    for(int i = 1; i <= min(n, 9); i++){
        freq[i * 10 + i]++;
    }
    for(int i = 11; i < 100; i++){
        if(i % 10 == 0) continue;
        string s = to_string(i);
        reverse(s.begin(), s.end());
        int x = (s[0] - '0') * 10 + s[1] - '0';
        ans += freq[i] * freq[x];
    }
    cout << ans;

    return 0;
}
