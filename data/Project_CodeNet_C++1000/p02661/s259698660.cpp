#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(0);
    vector<ll> v , vv;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        ll x , y;
        cin >> x >> y;
        if (n % 2 == 0)
        {x *= 2;
        y *= 2;}
        v.push_back(x);
        vv.push_back(y);
    }
    sort(v.begin() , v.end());
    sort(vv.begin() , vv.end());
    ll st;
    if (n % 2 == 1)st = v[(n-1)/2];
    else st = (v[(n-1)/2+1] + v[(n-1)/2])/2;
    ll en;
    if (n % 2 == 1)en = vv[(n-1)/2];
    else en = (vv[(n-1)/2+1] + vv[(n-1)/2])/2;
    //cout << st << " " << en << endl;
    cout << en - st + 1 << endl;
    return 0;
}
