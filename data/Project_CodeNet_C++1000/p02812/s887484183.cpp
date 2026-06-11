#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    rep(i, n-2) {
        if(s.substr(i,3) == "ABC") ans++;
    }
    cout << ans << endl;

    return 0;
}