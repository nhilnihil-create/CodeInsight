#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;
#define rep1(i,n) for (int i=1; i<=n; i++)
#define rep0(i,n) for (int i=0; i<n; i++)
#define zarray(x,n) x[n+1]; rep1(i,n) {x[i]=0;} 

int main() {
    string s;
    cin >> s;

    int aa[2020] = {0};
    
    aa[0] = 1;
    int a = 0;
    int c = 1;
    for (int j=(int)s.length()-1; j>=0; j--) {
        a += (s[j] - '0') * c;
        a %= 2019;
        aa[a]++;
        c *= 10;
        c %= 2019;
    }

    ll ans = 0;
    for(int mod : aa) {
        if (mod == 0) continue;
        ans += mod*(mod-1)/2;
    }

    cout << ans << endl;
}
