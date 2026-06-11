#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, st = 1;
    cin >> n;
    vector<pair<int, int>> v;

    for(int i=0; i<n; i++){
        int t;
        cin >> t;

        v.push_back(make_pair(t, i+1));
    }

    sort(v.begin(), v.end());

    for(int i=0; i<n; i++){
        cout << v[i].second << ' ';
    }

    return 0;
}