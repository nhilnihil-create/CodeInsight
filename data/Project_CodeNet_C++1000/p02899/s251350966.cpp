#include <bits/stdc++.h>
using namespace std;


//defines...
#define ll long long
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define in insert
#define pi 2*acos(0.0)1
#define srt(s) sort(s.begin(),s.end())
#define rsrt(s) sort(s.rbegin(),s.rend())
#define all(x) x.begin(),x.end()

const ll mod=1e9+7;
const ll MX=2e5+5;

//code goes from here...



int main()
{
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);
#endif

    boost
    //---------------------------------
    ll n;
    cin >> n;
    vector <ll> v(n);
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin >> x;
        v[x-1]=i+1;
    }
    for(auto i : v) cout << i << ' ';
    cout << endl;

    //---------------------------------
    
    return 0;
}
