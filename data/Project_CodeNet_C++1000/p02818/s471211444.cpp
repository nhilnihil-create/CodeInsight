/*
    Created by Tejas Chaudhari
    link:
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef double lf;
typedef bool bl;
typedef vector<ll> vl;
typedef vector<lf> vd;
typedef vector<bl> vb;
typedef string st;
typedef pair<ll,ll> pll;

#define INF (LONG_LONG_MAX / 4)
#define SORT(x) sort(x.begin(), x.end())
#define Mod % 1000000007

void re_curse() {
    ll a, b, k;
    cin>>a>>b>>k;
    if (k <= a) {
        cout<<a-k<<" "<<b<<endl;
    } else if (k <= b+a) {
        cout<<"0 "<<b+a - k<<endl;
    } else {
        cout<<"0 0"<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    for (int i = 1; i <= t; ++i) {
        re_curse();
    }
    return 0;
}
