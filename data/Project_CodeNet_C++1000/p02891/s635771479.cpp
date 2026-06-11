#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long int
#define mod 1000000007
#define string_mod 2549536629329_base_255
#define pb push_back
#define F first
#define S second
#define ff first
#define endl "\n"
#define ss second
#define all(v) v.begin(), v.end()
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int power(int x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res % p;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    tc = 1;
    //cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;
        string t = s;
        int k;
        cin >> k;
        int ans = 0;
        map<char, int> mp;
        int c = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i]] == 0)
            {
                mp[s[i]] = 1;
                c++;
            }
        }
        if (c == 1)
        {
            int f = s.size();
            f = f * k;
            f /= 2;
            cout << f << endl;
            continue;
        }
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
            {
                char ch = 'a';
                if (ch == s[i - 1] || ch == s[(i + 1) % s.size()])
                {
                    ch++;
                }
                if (ch == s[i - 1] || ch == s[(i + 1) % s.size()])
                {
                    ch++;
                }
                s[i] = ch;
                ans++;
            }
        }
        ans = ans * k;
        if (s[0] == s[s.size() - 1])
        {
            int c = 0;
            for (int i = 0; i < t.size();i++){
                if(t[i]==t[0]){
                    c++;
                }
                else
                {
                    break;
                }
                
            }
            reverse(all(t));
            for (int i = 0; i < t.size(); i++)
            {
                if (t[i] == t[0])
                {
                    c++;
                }
                else
                {
                    break;
                }
            }

            if(c%2==0)
            ans += k - 1;
        }
        cout << ans << endl;
    }

    return 0;
}