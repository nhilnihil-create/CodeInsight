#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    set<int> a;
    rep(i,k) {
        int d;
        cin >> d;
        rep(i,d) {
            int b;
            cin >> b;
            a.insert(b);
        }
    }
    int sum = 0;
    rep(i,n) {
        if (find(a.begin(), a.end(), i+1) == a.end())
            sum++;
    }
    cout << sum << endl;
    return 0;
}
