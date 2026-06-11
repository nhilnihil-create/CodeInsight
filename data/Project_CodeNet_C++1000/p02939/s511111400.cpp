//#pragma GCC optimize ('O3')
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 5e3 + 5;
const int M = 17 + 5;
const int W = 1000 + 5;
const int OO = 2e9;
const int mod = 1e9 + 7;

int ans;
string s;
char l;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;

    l = '#';

    for (int i = 0; i < s.size(); ++i) {
        if(s[i]==l) {
            if(i!=s.size()-1) {
                ++i;
                ++ans;
                l = '#';
            }
        } else {
            ++ans;
            l = s[i];
        }
    }

    cout << ans << '\n';

    return 0;
}