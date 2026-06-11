#include <bits/stdc++.h>
#define ll long long int
#define ld long double
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
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    vector<int> nums(n);
    rep(i, n) nums[i] = i;
    ld sum = 0;
    ld cnt = 0;
    do {
        rep(i, n -1) {
            ld dx = x[nums[i]] - x[nums[i+1]];
            ld dy = y[nums[i]] - y[nums[i+1]];
         //   cout << dx << " " << dy << endl;
            ld dist = sqrtl(dx * dx + dy * dy);
            sum += dist;
        }
        cnt ++;
    } while (next_permutation(nums.begin(), nums.end()));
    printf("%.10Lf\n", sum / cnt);
    return 0;
}