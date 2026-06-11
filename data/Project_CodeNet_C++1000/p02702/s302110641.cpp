#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n); ++i)
typedef long long ll;

const int mod = 1e9+7;
const int INF = 2000000;
const double PI = acos(-1.0);

int main() {
    string s;
    cin >> s;
    int c[2019] = {};
    c[0]++;
    int a = 0;
    int multiply = 1;
    for(int i = 1; i <= s.size(); ++i) {
        int n = s[s.size()-i] - '0';
        a = (n * multiply + a) % 2019;
        multiply = multiply * 10 % 2019;
        c[a]++;
    } 

    int ans = 0;
    for (int i = 0;i < 2019; i++) {
        ans += c[i]*(c[i]-1)/2;
    }
    
    cout << ans << endl;
}
