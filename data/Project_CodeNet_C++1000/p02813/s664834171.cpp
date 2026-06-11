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
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    vector<int> q(n);
    rep(i, n) cin >> q[i];


    vector<int> nums(n);
    rep(i, n) nums[i] = i + 1;
    
    int cnt = 0;
    int a = -1, b = -1;
    do {
        bool ok = true;
        rep(i, n) if (nums[i] != p[i]) {
            ok = false;
            break;
        } 
        if (ok) a = cnt;

        ok = true;
        rep(i, n) if (nums[i] != q[i]) {
            ok = false;
            break;
        } 
        if (ok) b = cnt;

        if (a >= 0 && b >= 0) {
            put(abs(a - b));
            return 0;
        }
        cnt++;
    } while (next_permutation(nums.begin(), nums.end()));

    return 0;
}