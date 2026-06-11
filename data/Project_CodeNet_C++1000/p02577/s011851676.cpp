#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int main()
{
    fio;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    cin>>s;
    ll ans = 0;
    for(ll i=0;i<s.length();i++)
    {
        ans += (s[i] - '0');
    }
    cout<<(ans%9 ? "No" : "Yes");
    return 0;
}