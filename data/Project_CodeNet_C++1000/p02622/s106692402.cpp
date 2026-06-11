#include <algorithm>
#include <iostream>
#include <string>

typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i <= b; i++)
#define all(a)  begin((a)),end((a))
#define uniq(c) (c).erase(unique(all((c))), end((c)))
#define each(i, map) for (auto& i : map)

int main()
{
    string S, T; cin >> S >> T;

    int ans = 0;
    for (int i = 0; i < S.length(); ++i) {
        if (S.at(i) != T.at(i)) ++ans;
    }
    cout << ans << endl;
}
