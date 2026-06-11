#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define pb push_back
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long ll;
#define reps(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define rreps(i,a,b) for(ll i=ll(a);i>=ll(b);--i)
#define mi map<int,int>
#define rep(i,b) for(ll i=0;i<ll(b);i++)
typedef vector<long long> vll;
typedef vector<pair<int,int>> vii;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int main()
{
    csl;
    string s,t;
    cin >> s >> t;
    int ans = t.size();
    for(int i=0;i<=s.size()-t.size();i++)
    {
        int fi = 0;
        for(int j=0;j<t.size();j++)
        {
            if(t[j]!=s[i+j])
                fi++;
        }
        ans = min(ans,fi);
    }

    cout << ans << endl;
}
