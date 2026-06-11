#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int mxK = 100;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if (k>mxK)
        k = mxK;
    vector<int> a(n);
    for (int i=0; i!=n; ++i)
        cin >> a[i];
    while (k--) {
        vector<int> b(n+1, 0);
        for (int i=0; i!=n; ++i) {
            int l=max(0,i-a[i]), r=min(n-1, i+a[i]);
            ++b[l];
            --b[r+1];
        }
        for (int i=0; i!=n; ++i)
            b[i+1]+=b[i];
        a=b;
    }
    for (int i=0; i!=n; ++i)
        cout << (i==0?"":" ") << a[i];
    return 0;
}
