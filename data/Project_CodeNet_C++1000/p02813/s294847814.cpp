#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mtv(kit) cout<<#kit<<" - "<<kit<<"\n";
#define ff first
#define ss second
#define pb push_back
#define rep(i,a,b) for(i=a;i<b;i++)
#define pii pair<ll , ll>
#define all(x) x.begin(),x.end()
#define nl "\n"
#define ump unordered_map

void doit(){
    ll n, i, j;
    cin >> n;
    vector< ll >v1(n),v2(n),v(n);
    for(i = 0; i < n; i++)cin>>v1[i];
    for(i = 0; i < n; i++)cin>>v2[i];
    iota(all(v),1);
    
    ll c1 = 0,c2 = 0,cur = 0;
    do{
        cur++;
        if(v == v1)c1 = cur;
        if(v == v2)c2 = cur;        
    }
    while(next_permutation(all(v)));
    cout << abs(c1-c2) << nl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    for(ll i = 1; i <= t; i++){
        doit();
    }
}
