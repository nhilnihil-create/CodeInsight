#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


bool prop(pair<ll, ll> p1, pair<ll, ll> p2)
{
   return p1.second < p2.second || (p1.second == p2.second && p1.first < p2.first); 
}

int main(){
    ll n;
    cin >> n;

    vector< pair<ll, ll> > ab;
    ll a, b;
    for(size_t i = 0; i < n; ++i)
    {
        cin >> a >> b;
        ab.push_back(make_pair(a,b));
    }
    sort(ab.begin(), ab.end(), prop);

    ll t = 0;
    for(size_t i = 0; i < n; ++i)
    {
        t += ab[i].first;
        if(t > ab[i].second){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
