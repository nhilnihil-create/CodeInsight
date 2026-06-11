#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for (int i = m; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int k, x;
    cin >> k >> x;
    
    vector<int> v;
    rep2 (i, x-k+1, x + k-1+1) {
        if (-1000000 <= i && i <= 1000000) {
            v.push_back(i);
        }
    }
    rep(i, v.size()) cout << v[i] << (i == v.size() - 1 ? "" : " ");
    cout << endl;

    return 0;
}