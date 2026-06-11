#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define endl '\n'
vector<ll> solve(ll n){
    vector<ll>v;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            v.push_back(i);
            if(i * i != n)
                v.push_back(n/i);
        }
    }
    return v;
}
int main()
{
    Hello
    ll n, ans;
    cin >> n;
    vector<ll> v = solve(n - 1);
    vector<ll> V = solve(n);
    ans = v.size() - 1;
    for(int i = 0; i < V.size(); i++){
        ll temp = n;
        while(V[i] != 1 && temp % V[i] == 0)
            temp /= V[i];
        if(temp % V[i] == 1)
            ans++;
    }
    cout << ans;
    return 0;
}