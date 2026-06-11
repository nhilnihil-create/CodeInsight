/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+5;

const int mod = 1e9+7;

string s;
long long ans;
long long p2[N];
long long p3[N];

int main(){
    p2[0] = p3[0] = 1;
    for(int i = 1; i < N; i++){
        p2[i] = p2[i - 1] * 2;
        p3[i] = p3[i - 1] * 3;
        p2[i] %= mod;
        p3[i] %= mod;
    }
    int cnt1 = 0;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1'){
            ans += (p2[cnt1] * p3[s.size() - i - 1]) % mod;
            ans %= mod;
            cnt1++;
        }
    }
    ans += p2[cnt1];
    ans %= mod;
    cout << ans << endl;
}