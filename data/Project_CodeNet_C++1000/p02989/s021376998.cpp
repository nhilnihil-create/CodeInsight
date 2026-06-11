#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    sort(a.begin(), a.end());

    int cnt = 0;
    for(int k = 0; k <= 200000; k++) {
        auto itr = lower_bound(a.begin(), a.end(), k);
        if(itr - a.begin() == a.end() - itr)cnt++;
    }
    cout << cnt << endl;
}