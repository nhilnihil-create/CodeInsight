#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;

    for(int i = 0; i < 1000; i++) {
        int a[3] = {i / 100, (i / 10) % 10, i % 10};
        int cou = 0;
        for(int j = 0; j < n; j++) {
            if(a[cou] == (s[j] - '0')) cou++;
            if(cou == 3) break;
        }
        if(cou == 3) ans++;
    }

    cout << ans << endl;

    return 0;
}