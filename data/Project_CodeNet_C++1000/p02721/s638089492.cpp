#include<bits/stdc++.h>
using namespace std;

#define int long long

#define pb push_back
#define F first
#define S second
#define I insert
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()

#define debug1(a) cout<<" "<<#a<<" : "<<a<<"\n"
#define debug2(a,b) cout<<" "<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<"\n"
#define debug3(a,b,c) cout<<" "<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<"\n"
#define debug4(a,b,c,d) cout<<" "<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<"\n"

#define INF (int)10000000000000000
#define PI (double)3.14159265358979
// #define M 421412341324321
#define MOD 1000000007


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

   	int n, k, c;
    cin>>n>>k>>c;
    string s;
    cin>>s;
    int pre = -1;
    vector <int> a(sz(s), LLONG_MAX);
    int cnt = 0;
    for (int i=0;i<n;++i)
    {
        if (cnt==k)
            break;
        if (s[i]=='x')
            continue;
        else
        {
            if (pre==-1)
            {
                a[i] = cnt;
                cnt++;
                pre = i;
            }
            else
            {
                if (i-pre>c)
                {
                    // debug1(i);
                    a[i] = cnt;
                    cnt++;
                    pre = i;
                }
            }
        }
    }
    vector <int> ans;
    cnt = 0, pre = -1;
    for (int i=n-1;i>=0;--i)
    {
        if (cnt==k)
            break;
        if (s[i]=='x')
            continue;
        else
        {
            if (pre==-1)
            {
                pre = i;
                if (a[i]==k-cnt-1){
                    ans.pb(i+1);
                }
                cnt++;
            }
            else
            {
                if (pre-i>c)
                {
                    if (a[i]==k-cnt-1)
                        ans.pb(i+1);
                    cnt++;
                    pre = i;
                }
            }
        }
    }
    sort(all(ans));
    // reverse(all(ans));
    for (auto j:ans)
        cout<<j<<"\n";

    return 0;
}