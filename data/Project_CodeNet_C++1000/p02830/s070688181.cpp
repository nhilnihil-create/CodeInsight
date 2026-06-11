#include<bits/stdc++.h>
using namespace std;
using ll =  long long;
int main()
{
    int n;
    cin >> n;
    string s, t, ans;
    cin >> s >> t;
    for (int i = 0; i < n; ++i)
    {
        ans+=s[i];
        ans+=t[i];
    }
    cout << ans  << endl;
}
