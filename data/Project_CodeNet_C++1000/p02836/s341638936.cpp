#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    string s;
    cin >> s;
    int cnt = 0;
    string kaibun = s;
    reverse(kaibun.begin(), kaibun.end());
    rep(i, s.length()){
        if(s[i]!=kaibun[i]) cnt++;
    }
    cout << cnt/2 << endl;
    return 0;
}
