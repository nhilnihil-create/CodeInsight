#include<bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;

using ll = long long;
const int N = 1e5+5;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        ++ans;
        int j = i;
        while(s[j+1] == s[i]) {
            ++j;
        }
        i = j;
    }
    cout << ans;
    return 0;
}
