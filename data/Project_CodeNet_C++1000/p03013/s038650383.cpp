#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int n,m;
    cin >> n >> m;
    vector<int> a(m+2);
    a[0]=0;
    for(int i = 0; i < m; i++) {
        cin >> a[i+1];
    }
    a[m+1]=n;

    vector<ll> p(n+1);
    p[0]=1;
    p[1]=1;
    for(int i = 2; i <= n; i++) {
        p[i]=(p[i-1]+p[i-2])%1000000007;
    }

    if(m==0){
        cout << p[n] << endl;
        return 0;
    }

    ll tstep = p[a[1]-1];

    for(int i = 1; i < m; i++) {
        int x=a[i+1]-a[i]-2;
        if(x==-1){
            cout << 0 << endl;
            return 0;
        }
        ll y=p[x];
        tstep *= y;
        tstep %= 1000000007;
    }
    
    tstep *= p[n-a[m]-1];
    tstep %= 1000000007;

    cout << tstep << endl;
    return 0;
}