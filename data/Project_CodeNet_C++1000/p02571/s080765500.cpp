#define inf 9223372036854775807
#define ll long long
#define pii pair<ll,ll>
#define m_p  make_pair
#define ull unsigned long long
#define spd  ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
int main()
{
    spd

    string s,t;
    ll n,i,j,k;

    cin>>s>>t;
    ll mn = t.size();
     n = s.size();
     k = t.size();

    for(i=0;i<=n-k;i++)
    {
        ll cnt = 0;
        ll idx = 0;
        for(j=i;j<i+k;j++)
        {
            if(s[j]!=t[idx])
            {
                cnt++;
            }

            idx++;
        }
        mn = min(mn,cnt);
    }

    cout<<mn<<endl;
}
