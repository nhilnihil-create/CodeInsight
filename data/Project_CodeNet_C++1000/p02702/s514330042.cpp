#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n) ; i++)
#define rrep(i,n) for(int i = n-1; i >= 0 ; i--)
typedef long long ll;
constexpr auto INFI = 2147483647;
const ll INFL = 9223372036854775807;

int main(){
    string s;
    cin >> s;
    int s_length = s.size();
    int ans = 0;
    vector<int> count(2020, 0);
    reverse(s.begin(), s.end());
    int x = 1;
    int modSum = 0;
    rep(i, s_length) {
        count[modSum]++;
        modSum = (modSum + (s[i] - '0') * x) % 2019;
        ans += count[modSum];
        x = (x*10) % 2019;
    }

    cout << ans << endl;

    return 0;
}