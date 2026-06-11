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

bool isOK(vector<int>& p) {
    rep(i, p.size() - 1) {
        if (p[i] > p[i+1]) {
            return false;
        }
    }
    return true;
}
signed main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    if (isOK(p)){
        println("YES");
        return 0;
    }


    
    rep(i, n - 1) rep2(j, i+1, n) {
        auto q = p;
        swap(q[i], q[j]);
        if (isOK(q)){
            println("YES");
            return 0;
        }
    }
    println("NO")
    return 0;
}