#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, x, y, z;
    bool ans = false;
    cin>>n;
    map<int, int>mapp;
    y = n / 3;
    z = y + y;
    for(i = 0; i < n; i++)
    {
        cin>>x;
        mapp[x]++;
    }
    if(mapp.size() == 1)
    {
        if(mapp.begin()->first == 0)
            ans = true;
    }
    else if(mapp.size() == 2 && (n % 3) == 0)
    {
        if(mapp.begin()->first == 0)
        {
            if(mapp.begin()->second == y)
            {
                if((++(mapp.begin()))->second == z)
                    ans = true;
            }
        }
    }
    else if(mapp.size() == 3 && (n % 3) == 0)
    {
        int f, s, t;
        f = (mapp.begin())->first;
        s = (++(mapp.begin())) ->first;
        t = (++(++(mapp.begin()))) ->first;
        if((f^s^t) == 0)
        {
            if(mapp[f] == mapp[s] && mapp[s] == mapp[t])
                ans = true;
        }
    }
    ans ? cout<<"Yes" : cout<<"No";
    return 0;
}
