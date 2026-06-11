#include <bits/stdc++.h>

using namespace std;

long long ans,n,p,cur,t,cnt[100010];
string s;

int main()
{
    cin >> n >> p >> s;
    
    if(p == 2 || p == 5)
    {
        for(int i = 0;i < n;i++)
            if((s[i] - '0') % p == 0) ans += i+1;
    }
    else
    {
        cnt[0] = 1,t = 1;
        for(int i = n-1;i >= 0;i--)
        {
            cur = (cur + t*(s[i] - '0')%p) % p;
            t = t*10 % p;
            ans += cnt[cur]++;
        }
    }
    
    cout << ans << endl;
    return 0;
}