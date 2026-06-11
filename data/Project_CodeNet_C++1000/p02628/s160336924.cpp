#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    sort(p.begin(), p.end());
    int sum = 0;
    rep(i, k) {
        sum += p[i];
    }
    println(sum)
    return 0;
}