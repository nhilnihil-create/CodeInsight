#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef vector<int> vi;


int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.rbegin(), a.rend());

    vector<int> resx(n-1),resy(n-1);
    int pos = 0;
    if(a[0]*a[n-1] <= 0) {
        for(int i = 1; i < n-1; ++i) {
            if(a[i] >= 0) {
                resx[pos] = a[n-1], resy[pos] = a[i];
                pos++;
                a[n-1] -= a[i];
            }
        }

        for(int i = 1; i < n; ++i) {
            if(a[i] < 0) {
                resx[pos] = a[0], resy[pos] = a[i];
                pos++;
                a[0] -= a[i];
            }
        }
    }
    else if(a[0] > 0 && a[n-1] > 0) {
        for(int i = 1; i < n-1; ++i) {
            resx[pos] = a[n-1], resy[pos] = a[i];
            pos++;
            a[n-1] -= a[i];
        }

        resx[pos] = a[0], resy[pos] = a[n-1];
        a[0] -= a[n-1];
    }
    else if(a[0] < 0 && a[n-1] < 0) {
        for(int i = 1; i < n; ++i) {
            resx[i-1] = a[0], resy[i-1] = a[i];
            a[0] -= a[i];
        }
    }

    cout << a[0] << endl;
    rep(i,n-1) cout << resx[i] << ' ' << resy[i] << endl;

    return 0;
}