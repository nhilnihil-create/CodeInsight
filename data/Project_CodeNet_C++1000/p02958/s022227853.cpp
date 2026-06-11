#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> ps(n);
    for(int i=0; i<n; i++) cin >> ps.at(i);

    vector<int> as(n);
    iota(as.begin(), as.end(), 1);
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        if(ps.at(i) != as.at(i)) cnt++;
    }

    if(cnt==0 || cnt==2) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
