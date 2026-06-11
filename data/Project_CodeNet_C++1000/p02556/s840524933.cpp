#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define pii pair<ll,ll>

#define debug(a) { cout << #a << " = " << a << endl;}

void sep() {
    cout << "-------------BLOCK-----------------\n";
}

template<typename T>
void debugv(vector<T> arr) {
    for (auto t: arr)
        cout << t << " ";
    cout << "\n";
}

template<typename T>
void debugarr(T arr, int n) {
    for (int i=0;i<n;i++) cout << arr[i] << " ";
    cout << "\n";
}

const int maxn = 1e5+1;
ll arr[maxn], n, m, t, k;
unordered_map<ll,ll> u;

ll __min(ll a, ll b) {
    return a < b ? a : b;
}

ll __max(ll a, ll b) {
    return a > b ? a : b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    ll maxp=INT_MIN;
    ll minp=INT_MAX;
    ll maxs=INT_MIN;
    ll mins=INT_MAX;

    ll x,y;
    ll ans=0;
    while (n--) {
        cin>>x>>y;
        maxp=__max(maxp,x+y);
        minp=__min(minp,x+y);
        maxs=__max(maxs,x-y);
        mins=__min(mins,x-y);
        ans=__max(maxp-minp,maxs-mins);
    }
    cout << ans << endl;
}
