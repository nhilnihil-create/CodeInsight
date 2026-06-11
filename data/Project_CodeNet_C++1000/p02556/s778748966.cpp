#include<bits/stdc++.h>
#include<string>
#include<cmath>

using namespace std;

#define ll long long int
#define ld long double
#define pb push_back
#define all(v) v.begin(),v.end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define deb(x) cout<< #x << '=' << x <<endl
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    ll x[n] , y[n];
    for(int i = 0; i < n; i++){
        cin>>x[i]>>y[i];
    }
    ll mn1 = INT_MAX, mx1 = INT_MIN , mn2 = INT_MAX , mx2 = INT_MIN;
    for(int i = 0; i < n; i++){
        mx1 = max(mx1, x[i] + y[i]);
        mn1 = min(mn1 , x[i] + y[i]);
        mx2 = max(mx2 , x[i] - y[i]);
        mn2 = min(mn2 , x[i] - y[i]);
    }
    cout<<max(mx1 - mn1 , mx2 - mn2);
}