#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007
#define X first
#define Y second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
string s;
int cnt;

int main()
{
    cin >> s;
    for (int i = 0; i < s.size() / 2; ++i) if (s[i] != s[s.size() - 1 - i]) ++cnt;
    cout << cnt;
    return 0;
}
