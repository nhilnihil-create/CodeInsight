/**So..a**/
#include<bits/stdc++.h>

using namespace std;
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define PB(x, v) x.push_back(v);
#define pll pair<ll, ll>
#define ll long long
#define mll map<ll, ll>
#define vl vector<ll>

#define fa(x, v) for(auto x: v)
#define fr(i, a, b) for(int i= a;i <=b; i++)

#define B_ begin()
#define E_ end()
#define all(a) a.begin(), a.end()
#define NL_ "\n"

#define MAX 2000000000
#define F first
#define S second
#define FF first.first
#define FS first.second
#define SF second.first
#define SS second.second

#define mod(a) a%1000000007


int main()
{
    FAST;
    ll n;
    cin >> n;
    ll arr[n];
    for(ll i=0; i< n; i++)
    {
        cin >> arr[i];
    }
    ll mn = LLONG_MAX;
    ll cnt= 0;
    for(int i = 0; i< n; i++)
    {
           mn = min(arr[i], mn);
           if(mn>=arr[i]) cnt++;
    }
     cout << cnt<<NL_;

    return 0;
}