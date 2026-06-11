#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T> inline bool chmax(T &a, T b)
{
    if(a < b)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    ll mod = static_cast<ll>(1e9+7);

    vector<vector<ll>> dp(s.length()+1, vector<ll>(13, 0));
    if(s.at(0) == '?')
    {
        for(int i=0; i<10; i++)
        {
            dp.at(0).at(i)++;
        }
    }
    else
    {
        int num = s.at(0) - '0';
        dp.at(0).at(num)++;
    }
    
    for(int i=1; i<s.length(); i++)
    {
        if(s.at(i) == '?')
        {
            for(int j=0; j<10; j++)
            {
                for(int k=0; k<13; k++)
                {
                    dp.at(i).at((10*k+j)%13) += dp.at(i-1).at(k);
                    dp.at(i).at((10*k+j)%13) %= mod;
                }
            }
        }
        else
        {
            int num = s.at(i) - '0';
            for(int j=0; j<13; j++)
            {
                dp.at(i).at((j*10 + num) % 13) += dp.at(i-1).at(j);
            }
        }
    }
    cout << dp.at(s.length()-1).at(5) << endl;

    return 0;
}
