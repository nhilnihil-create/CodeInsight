#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, S, a, M=2000000000, Ma=0;
    cin >> n;
    S = (1 << n);
    multiset <int> Se;
    multiset <int> :: iterator it;
    vector <int> V, T;
    for (int i = 0; i < S; i++)
    {
        cin >> a;
        Ma = max(a, Ma);
        Se.insert(M-a);
    }
    Se.erase(Se.find(M-Ma));
    V.push_back(M-Ma);
    for (int i = 0; i < n; i++)
    {
        for (int y = 0; y < V.size(); y++)
        {
            it = Se.upper_bound(V[y]);
            if (it != Se.end())
            {
                T.push_back(*it);
                Se.erase(Se.find(*it));
            }
        }
        for (int y = 0; y < T.size(); y++)
        {
            V.push_back(T[y]);
        }
        T.clear();
        sort(V.begin(),V.end());
    }
    if (Se.size() == 0)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}
