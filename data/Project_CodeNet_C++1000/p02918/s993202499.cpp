#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    char c = s.front();
    int score = 0;
    for(int i=0; i<n-1; i++)
    {
        if(s.at(i) == s.at(i+1)) score++;
    }
    int ans = min(score + 2*k, n-1);
    cout << ans << endl;
    return 0;
}
