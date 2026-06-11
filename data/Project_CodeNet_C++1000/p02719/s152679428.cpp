#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "E:\CP\Debugger\debugger.h"
#else 
#define debug(x...)
#endif
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 

signed main(){
    int n, k; cin>>n>>k;

    int ans = min(n%k, abs(k-(n%k)));

    cout<<ans<<"\n";
}