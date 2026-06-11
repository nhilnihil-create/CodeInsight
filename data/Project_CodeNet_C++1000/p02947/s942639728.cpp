#include <bits/stdc++.h>
#include <string>
using namespace std;

typedef long long ll;

#define pf(n) cout << n << endl
#define ps() cout <<" ";
#define sf(n) cin >> n
#define in(i,n) for (int i = 0; i < n; i++) 2
#define mn -
#define pls +
#define mod %
#define E =
#define EE ==
#define le <=
#define ge >=

inline void SUM(ll &x,ll y)
{
    x=x+y;
}
inline void DIFF(ll &x,ll y)
{
    x=x-y;
}
inline void yes(int counter){
    if(counter EE 0)
    cout<<"yes\n";
    else if(counter EE 1)
    cout<<"Yes\n";
    else cout<<"YES\n";
    return;
}
inline void no(int counter){
    if(counter EE 0)
    cout<<"no\n";
    else if(counter EE 1)
    cout<<"No\n";
    else cout<<"NO\n";
    return;
}
ll c E 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int count;
    cin>>count;
    string str;
    std::map<string, int > mp;
    for (int i = 0; i < count; ++i)
    {
        cin>>str;
       sort(str.begin(), str.end());
       mp[str]++;
    }
    ll sum E 0;
    for(auto e : mp)
    {
        ll c E e.second;
        DIFF(c,1);
        c E ((c pls 1)*c)/2;
        SUM(sum,c);
    }
    cout<<sum<<endl;
    return 0;
}
