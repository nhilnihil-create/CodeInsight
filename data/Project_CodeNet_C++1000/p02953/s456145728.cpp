#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> hs(n);
    for(int i=0; i<n; i++) cin >> hs.at(i);

    int pre = -1;
    string ans = "Yes";
    for(auto &h : hs)
    {
        if(pre < h) h--;
        else if(pre > h)
        {
            ans = "No";
            break;
        }
        pre = h;
    }
    cout << ans << '\n';

    return 0;
}
