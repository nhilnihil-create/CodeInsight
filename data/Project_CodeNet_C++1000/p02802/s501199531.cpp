#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
    int n, m, tmp, acs = 0, pns = 0;
    string stmp;
    cin >> n >> m;
    vector<int> ac(n), pn(n);

    for(int i = 0; i < m; ++i)
    {
        cin >> tmp >> stmp;
        tmp--;
        if(ac[tmp])
            continue;
        if(stmp == "AC")
            ac[tmp] = 1;
        else if(stmp == "WA")
            pn[tmp]++; 
    }

    for(int i = 0; i < n; ++i)
    {
        acs += ac[i];
        if(ac[i]) pns += pn[i];
    }

    cout << acs << " " << pns << "\n";
    return 0;
}