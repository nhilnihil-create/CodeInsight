#include <bits/stdc++.h>

#define ll long long

using namespace std;

int bin_pow(int a, int x)
{
    if(x == 0) return 1;
    if(x % 2 == 0)
    {
        int b = bin_pow(a, x / 2);
        return b * b;
    }
    return a * bin_pow(a, x - 1);
}

multiset <int> s;

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int st,x;
    cin >> st;
    int n;
    n = bin_pow(2, st);
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        s.insert(x * (-1));
    }
    vector <int> cur;
    cur.push_back(*s.begin());
    s.erase(s.begin());
    for(int i = 0; i < st; i++)
    {
        vector <int> nv;
        for(int j = 0; j < cur.size(); j++)
        {
            if(s.upper_bound(cur[j]) == s.end())
            {
                return cout << "No", 0;
            }
            nv.push_back(*s.upper_bound(cur[j]));
            s.erase(s.upper_bound(cur[j]));
        }
        for(int j = 0; j < nv.size(); j++) cur.push_back(nv[j]);
    }
    cout << "Yes";
}
