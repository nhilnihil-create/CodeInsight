#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    int a;
    vector<P> s(n+1);
    
    for (int i = 1; i <= n; i++) {
        cin >> a;
        s[i].first = a;
        s[i].second = i;
    }
    sort(s.begin(), s.end());
    for (int i = 1; i <= n; i++) {
        cout << s[i].second << " ";
    }
    printf("\n");

    return 0;
}