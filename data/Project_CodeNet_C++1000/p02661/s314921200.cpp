#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> ls(n), rs(n);
    for(int i=0; i<n; i++) cin >> ls.at(i) >> rs.at(i);

    sort(ls.begin(), ls.end());
    sort(rs.begin(), rs.end());
    
    if(n%2)
    {
        cout << rs.at((n-1)/2) - ls.at((n-1)/2) + 1 << endl;
    }
    else
    {
        int lsum = ls.at(n/2-1) + ls.at(n/2);
        int rsum = rs.at(n/2-1) + rs.at(n/2);
        cout << rsum - lsum + 1 << endl;
    }

    return 0;
}
