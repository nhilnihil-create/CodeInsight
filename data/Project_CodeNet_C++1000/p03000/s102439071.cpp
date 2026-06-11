#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> l(n);
    rep(i, n) cin >> l[i];
    
    int p = 0;
    int cnt = 1;
    rep(i, n) {
        p += l[i];
        if (p <= x) 
            cnt++;
        else
            break;
    }

    put(cnt)

    return 0;
}