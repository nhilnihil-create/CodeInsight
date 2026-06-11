#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#define mod 1000000007
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define srep(i,s,t) for (ll i = s; i < t; i++)
#define drep(i,n) for(ll i = (n)-1; i >= 0; i--)
using namespace std;
typedef long long ll;
typedef vector<vector<char>> field_t;
typedef unsigned long long ull;
typedef pair<ll, ll> point_t;


int main()
{
    ll k;
    cin >> k;
    ll ans=0;
    vector<ll> a(k);
    rep(i,k){
        cin>>a[i];
        if(i%2==0){
            if(a[i]%2!=0){
                ans++;
            }
        }
    }
    cout<< ans << endl;
    return 0;
}