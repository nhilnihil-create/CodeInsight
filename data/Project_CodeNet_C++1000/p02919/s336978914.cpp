#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define pii pair<int,int>
const int mod = 1e9 + 7;
set<int>st;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    st.insert(0);
    st.insert(n+1);
    vector<pair<int,int>>v;
    f1(n) {
        int x;
        cin >> x;
        v.pb({x,i});
    }
    sort(all(v));
    reverse(all(v));
    ll ans = 0;
    for (auto &i : v) {
        auto x = st.lower_bound(i.S);
        if (*x != n + 1) {
            ans += (ll)i.F * (*next(x)-*x) * (i.S - *prev(x));
            //cout << *next(x) <<' '<<*x<<' '<<i.S<<' '<<*prev(x)<<endl;
        }
        x = prev(x);
        if (*x != 0) {
            ans += (ll)i.F * (*next(x) - i.S) * (*x - *prev(x));
        }
        st.insert(i.S);
    }
    cout << ans << '\n';
}
