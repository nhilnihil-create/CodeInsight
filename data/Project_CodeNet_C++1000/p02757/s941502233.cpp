#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, p;
    cin >> n >> p;
    vector<char>s(n + 3);
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    long long ans = 0;
    if(p == 2){
        for(int i = 1; i <= n; i++){
            if((s[i] - '0') % 2 == 0){
                ans = ans + 1LL * i;
            }
        }
        cout << ans;
        return 0;
    }
    if(p == 5){
        for(int i = 1; i <= n; i++){
            if((s[i] - '0') % 5 == 0){
                ans = ans + 1LL * i;
            }
        }
        cout << ans;
        return 0;
    }
    vector<int>power(n + 3);
    power[0] = 1;
    for(int i = 1; i <= n; i++){
        power[i] = (10 * power[i - 1]) % p;
    }
    vector<int>v(n + 3), pref(n + 3), cnt(p + 3, 0);
    for(int i = n; i >= 1; i--){
        int d = s[i] - '0';
        v[i] = d * power[n - i];
    }
    pref[0] = 0;
    cnt[0] = 1;
    for(int i = 1; i <= n; i++){
        pref[i] = (pref[i - 1] + v[i]) % p;
        cnt[pref[i]]++;
    }
    for(int i = 0; i < p; i++){
        long long cur = (1LL * cnt[i] * (cnt[i] - 1))/2;
        ans = ans + cur;
    }
    cout << ans;
    return 0;
}