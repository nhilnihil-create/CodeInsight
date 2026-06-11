#include<bits/stdc++.h>
#include<vector>
#define ll long long
#define boostUP ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fsr(i,n) for(ll i=0;i<n;i++)
#define fcr(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define sz(arr) sizeof(arr)/sizeof(arr[0])

using namespace std;
ll helper(ll h){
    ll res = 1, res2 = 1;
    while(h > 1){
        res2 *= 2;
        res += res2;
        h = h >> 1;
    }
    return res;
}
int main(){
    ll h; cin >> h;
    cout << helper(h);
}











