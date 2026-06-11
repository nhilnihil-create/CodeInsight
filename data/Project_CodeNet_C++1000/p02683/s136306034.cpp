#include <bits/stdc++.h>
#include <iostream>
#include <math.h>    //pow(x,y)=x^y 99999とかの場合+1するif文
#include <algorithm> //sort(a.begin(), a.end());reverse(a.begin(), a.end());
#define rep(init, i, n) for (int i = init; i < (n); i++)
#define ll long long
#define rev(s) reverse(s.begin(), s.end())
#define sor(v) sort(v.begin(), v.end())
#define PI 3.14159265358979323846264338327950
//コード自動整形 Shift + Option + F @vscode
using namespace std;

/////main/////
int main()
{
    ll n, m, x;
    cin >> n >> m >> x;
    vector<ll> c(n);

    vector<vector<ll>> a(n, vector<ll>(m));
    rep(0, i, n)
    {
        cin >> c.at(i);
        rep(0, j, m)
        {
            cin >> a.at(i).at(j);
        }
    }

    ll output = 100000000;

    ll bitmax = 1 << (n);
    bitmax -= 1;
    //cout << "bitmax=" << bitmax << endl;//
    ll sum;
    ll count;

    rep(0, k, bitmax)
    {
        ll kingaku = 0;
        ll ntemp = 0;
        ll bittemp = k;
        rep(0, i, n)
        {
            bittemp = k;
            if ((bittemp >> i & (ll)1)==0)//(bittemp >> i & (ll)1)
            {
                ntemp++;
            }
        }
        //cout << "ntemp=" << ntemp << endl;//
        sum = 0;
        count = 0;
        vector<ll> rikaido(m);
        rep(0, i, n)
        {
            bittemp = k;
            if ((bittemp >> i & (ll)1)==0)
            {
                kingaku += c.at(i);
                rep(0, j, m)
                {
                    rikaido.at(j) += a.at(i).at(j);
                }
            }
        }
        rep(0, j, m)
        {
            if (rikaido.at(j) >= x)
            {
                count++;
            }
        }
        if (m == count)
        {
            output = min(output, kingaku);
        }
    }
    if (output == 100000000)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << output << endl;
    }
}
/////main/////

/////function/////