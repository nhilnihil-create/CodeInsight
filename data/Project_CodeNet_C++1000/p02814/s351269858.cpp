//-fexec-charset=CP932
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100
#define THOU 1000
#define FIVEMAX 100000
#define NINEMAX 1000000000
#define TWEMAX 1000000000000
#define rep(i,n) for (int i=0;i<n;i++)
#define drep(i,n) for(int i=n-1;i>=0;i--)
#define arep(i,a,n) for(int i=a;i<n;i++)
#define darep(i,a,n) for(int i=n,i>=a;i--)

ll gcd(ll x,ll y){
    if(x<y) swap(x,y);
 
    ll r;
    while(y>0){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

ll solve(int n, ll m, vector<ll> &a) {
    // 2 で割れるだけ割る (割れる回数が異なったらダメ)
    bool same = true;
    while (a[0] % 2 == 0) {
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 != 0) return 0;
            a[i] /= 2;
        }
        m/= 2;
    }
    for (int i = 0; i < n; ++i) if (a[i] % 2 == 0) return 0;

    // lcm
    ll lcm = 1;
    for (int i = 0; i < n; ++i) {
        ll g = gcd(lcm, a[i]);
        lcm = lcm / g * a[i];
        if (lcm > m) return 0;
    }
    return (m / lcm + 1) / 2;
}

int main(){
 cin.tie(0);
 ios::sync_with_stdio(false);
 string str;
 vector<int>v;
 //map<string,int>m;
 pair<int,int>p;
 int n;
 ll m;
 cin>>n>>m;
 vector<ll>a(n);
 for (int i = 0; i < n; ++i) cin >> a[i], a[i] /= 2;
    cout << solve(n,m,a) << endl;
//auto ans=
//cout<<ans<<endl;
return 0;
}

