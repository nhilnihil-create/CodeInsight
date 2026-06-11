#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main()
{
    ll N; cin >> N;
    vector<ll> a(N);
    vector<ll> b(N);
    for(int i = 0 ; i < N ; i++)
    {
        ll x,y;
        cin >> x >> y;
        a[i] = x+y;
        b[i] = x-y;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    cout << max(a[N-1] - a[0] , b[N-1] - b[0]);

}