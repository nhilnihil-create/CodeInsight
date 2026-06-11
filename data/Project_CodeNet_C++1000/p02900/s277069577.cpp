#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T> T euclidean_gcd(T a, T b)
{
    if(a < b) return euclidean_gcd(b, a);
    T r;
    while(r=a%b)
    {
        a = b;
        b = r;
    }
    return b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll A, B;
    cin >> A >> B;
    ll C = euclidean_gcd(A, B);

    vector<ll> yakusu;
    for(ll i=1; i*i<=C; i++)
    {
        if(C%i==0)
        {
            yakusu.push_back(i);
            if(i*i != C) yakusu.push_back(C/i);
        }
    }

    sort(yakusu.begin(), yakusu.end());
    // cout << yakusu.size() << endl;
    vector<ll> ans;
    for(int i=0; i<yakusu.size(); i++)
    {
        bool is_add = true;
        for(int j=0; j<ans.size(); j++)
        {
            if(euclidean_gcd(yakusu[i], ans[j]) != 1) is_add = false;
        }
        if(is_add) ans.push_back(yakusu[i]);
    }
    cout << ans.size() << endl;

    return 0;
}