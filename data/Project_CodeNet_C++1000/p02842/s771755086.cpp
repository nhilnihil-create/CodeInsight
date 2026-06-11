#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    int m = n*100/108;
    string ans = ":(";
    for(int i=m-100; i<m+101; i++)
    {
        if((int)((double)i*1.08) == n)
        {
            ans = to_string(i);
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
