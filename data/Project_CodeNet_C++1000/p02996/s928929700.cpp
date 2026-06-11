#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
    int n; cin >> n;
    vii arr;
    for (int i = 0; i < n ; i++)
    {
        int a, b; cin >> a >> b;
        arr.push_back(make_pair(b, a));
    }
    sort(arr.begin(), arr.end());
    ll count = 0; bool sol = true;
    for (int i = 0; i < n; i++)
    {
        count += arr[i].second;
        if (arr[i].first < count)
            sol = false;
    }
    if (sol)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}