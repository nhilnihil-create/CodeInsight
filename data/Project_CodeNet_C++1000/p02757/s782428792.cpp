#include <bits/stdc++.h>

using namespace std;

int n, p;
string s;
long long tbl[10000] = {0};

long long complx (long long a){
    if(a <= 1) return 0;
    return (a * (a - 1)) / 2;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> p;
    cin.ignore();
    cin >> s;
    cin.ignore();

    reverse(s.begin(), s.end());
    long long ans = 0;
    if(p == 2 || p == 5){
        for(int i = 0; i < s.size(); i++){
            if((s[i] - '0') % p == 0) ans += s.size() - i;
        }
        cout << ans << endl;
        return 0;
    }

    long long m = 0;
    long long te = 1;
    tbl[0] = 1;
    for(int i = 0; i < s.size(); i++){
        m += (s[i] - '0') * te;
        m %= p;
        ++tbl[m];
        te *= 10;
        te %= p;
    }

    for(int i = 0; i < p; i++){
        ans += complx(tbl[i]);
    }
    cout << ans << endl;
    return 0;
}