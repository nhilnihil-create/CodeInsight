#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll cnt = 0;
    rep(i, 0, n){
        if(i == 0 && s[i] == 'L') continue;
        if(i == n-1 && s[i] == 'R') continue;
        if(s[i] == 'R' && s[i+1] == 'R') cnt++;
        if(s[i] == 'L' && s[i-1] == 'L') cnt++;
    }
    ll rem = n - 1 - cnt;
    cerr << cnt << endl;
    if(rem >= 2*k){
        cout << cnt + 2*k << endl;
    }else{
        cout << n-1 << endl;
    }
    return 0;
}