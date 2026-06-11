#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(m);
    vector<string> s(m);
    rep(i, m) cin >> p[i] >> s[i];
    
    vector<int> wa(n);
    vector<int> ac(n);
    rep(i, m) {
        if (s[i] == "WA" && ac[p[i]-1] <= 0) {
            wa[p[i]-1]++;
        }
        else if (s[i] == "AC" && ac[p[i]-1] <= 0) {
            ac[p[i]-1]++;
        }
    }

    int pen = 0;
    rep(i, n) {
        if (ac[i] >= 1) pen += wa[i];
    }
    cout << accumulate(all(ac), 0) << " " << pen << endl;   

    return 0;
}