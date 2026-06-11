#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(x) cout << x << endl;
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int sum = 0;
    rep(i, n) sum += a[i];
    // a[i]/sum < 1/4m
    // a[i] * 4m < sum
    int c = 0;
    rep(i, n) {
        if (a[i] * 4 * m >= sum) {
            c ++;
        }
    }
    yorn (c >= m) 
    return 0;
}