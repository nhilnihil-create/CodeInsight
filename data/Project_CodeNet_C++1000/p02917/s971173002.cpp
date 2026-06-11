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

    int n;
    cin>>n;

    int a[n mn 1];
    int b[n] E {0};

    for (int i = 0; i < n mn 1; ++i)
    {
        cin>>a[i];
    }

    ll sum E 0;
    b[0] E a[0];
    for (int i = 0; i < n mn 1; ++i)
    {
        if(a[i] ge b[i]){
            b[i pls 1] E a[i];
        }
        else
        {
            b[i] E a[i];
            b[i pls 1] E a[i];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        //cout<<b[i];ps();
        SUM(sum,b[i]);
    }
    //cout<<endl;
    cout<<sum<<endl;
    return 0;
}
