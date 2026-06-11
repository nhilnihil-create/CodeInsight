#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define ll long long
#define ull unsigned long long
#define dd double
#define oo 1001007000
#define ff float
#define ooo 4223352036854775007
#define iii pair<ll,ll>
#define vii vector<ll>
#define viii vector<iii>
#define sss pair<str,str>
#define str string
#define sii set<ll>
#define siii set<iii>
#define r0 return 0
#define pb push_back
#define sz size
using namespace std;

const char E='\n';
const int N=200005;
const int NN=2005;
const ll md=998244353;



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    ll a[N]={0};
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    ll ans=a[1];
    multiset<ll> p;
    p.insert(-1*a[2]);
    p.insert(-1*a[2]);

    for (int i=3;i<=n;i++){
        //cout << *p.begin() << E;
        ans-=*p.begin();
        p.erase(p.find(*p.begin()));
        p.insert(-1*a[i]);
        p.insert(-1*a[i]);

    }
    cout << ans << E;
    return 0;
}


/*







*/
