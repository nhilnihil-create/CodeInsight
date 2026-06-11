#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    int cnt = 0;
    for(int i = 1; i < n - 1; i++) {
        vector<int> t = {a[i - 1], a[i], a[i + 1]};
        sort(t.begin(), t.end());
        if(t[1] == a[i])cnt++;
    }
    cout << cnt << endl;
}