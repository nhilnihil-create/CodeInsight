#include <bits/stdc++.h>
using namespace std;
#define rep(k,dst)    for(int i=k; i<dst;  i++)
#define rep2(k,dst)   for(int j=k; j<dst;  j++)
#define INF 1000000000000 //1e+12
#define MOD 10000007 //1e9+7
#define ll long long
#define pb pop_back
template<typename T> inline void chMin(T* a, T* b) {if(*a>*b) *a=*b;}
template<typename T> inline void chMax(T* a, T* b) {if(*a<*b) *a=*b;}
template<typename T> inline int  divUp(T a, T b)   {return ((a+b-1)/b);}
const double PI = acos(-1);

int main(){
    ll n, k; cin >> n >> k;
    ll ans=0;
    vector<ll> h(n);
    rep(0,n) cin >> h[i];

    sort(h.begin(), h.end());
    rep(0,k) h.pop_back();
    rep(0,n-k) ans += h[i];
    cout << ans << endl;
    return 0;
}
/*
3 3
1 7
3 2
1 7
*/
