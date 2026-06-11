#include<bits/stdc++.h>

#define forw(m,i,n) for(i=m; i<n; i++)
#define done return 0
#define in(x) cin >> x
#define out(x) cout << x << endl
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;



int main() {
    //freopen("output.txt","w",stdout);
    //freopen("input.txt","r",stdin);

    ll n;
    in(n);
    ll i,x,counts=1,minm=0;
    in(minm);
    for(i=1; i<n; i++) {
        in(x);
        if(x<=minm) counts++;
        minm=min(minm,x);
    }

    cout << counts << endl;
}
