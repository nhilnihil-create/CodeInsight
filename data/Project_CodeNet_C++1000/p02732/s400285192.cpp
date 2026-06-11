#include <bits/stdc++.h>
#define ll long long int
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int> 
#define vll vector<ll> 
#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " - " << x << endl;
const ll MOD = 1e9 + 7;
const ll INF = 1<<29;
const ll MAX_N = 1e6 + 7;
using namespace std;

ll get(ll x){
    return (x * (x-1) / 2);
}

int main() {
    IOS;
    int n; cin >> n;
    vll mp(n+2,0),v(n);
    for(int i=0;i<n;++i){
        cin >> v[i],mp[v[i]]++; 
    }
    ll sum = 0,temp;
    for(auto x:mp){
        sum += get(x);
    }
    
    for(int i=0;i<n;++i){
        ll type = v[i];
        temp = sum;
        temp -= get(mp[type]);
        ll temp1 = mp[type] - 1;
        temp += get(temp1);
        cout << temp << "\n";
    }
}