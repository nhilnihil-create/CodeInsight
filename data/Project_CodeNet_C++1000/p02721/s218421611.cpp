#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define f first
#define s second
const int N = 5e5+5;

int n , k , c;
string s;

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k >> c;
    cin >> s;
    s = ' '+s;

    vector<int> pre , suf;
    for(int i=1; i<=n; i++)
    {
        if (s[i] == 'o')
        {
            pre.push_back(i);
            i += c;
        }
    }
    for(int i=n; i>0; i--)
    {
        if (s[i] == 'o')
        {
            suf.push_back(i);
            i -= c;
        }
    }

    reverse(suf.begin() , suf.end());

    vector<int> v;
    for(int i=1; i<=n; i++)
    {
        if (s[i] == 'x') continue;
        int l = upper_bound(pre.begin() , pre.end() , i-1)-pre.begin() , nxt , s=0;
        l--;
        s += (l+1);
        if (l >= 0) nxt = max(i,pre[l]+c);
        else nxt = i;

        int r = upper_bound(suf.begin() , suf.end() , nxt) - suf.begin();
        s += (suf.size() - r);
        if (s < k) v.push_back(i);
    }

    for(auto i : v)
        cout << i << '\n';

    return 0;
}