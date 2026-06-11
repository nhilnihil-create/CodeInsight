#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <set>
#include <map>
#include <list>
#include <cstdlib>
#include <queue>
#include <stack>

using namespace std;

#define mod (1e9 + 7)
#define pi 3.1415926535897932
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, j, n) for (int i = j; i < n; i++)
#define repi(i, n) for (int i = 0; i <= n; i++)
#define repie(i, j, n) for (int i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl
#define P pair<int, int>
#define fi first
#define se second

typedef long long ll;

void solve1() {
    int n, m; cin >> n >> m;
    vector<int> s(m), c(m);
    for (int i = 0; i < m; i++)
    {
        cin >> s[i] >> c[i];
    }

    string num = "";
    vector<bool> nums(n);
    for(int i = 0; i < n; i++) {
        num += '0';
        nums[i] = true;
    }

    for(int i = 0; i < m; i++) {
        if(n > 1 && s[i] == 1 && c[i] == 0) {
            num = "-1";
            break;
        }

        if(nums[s[i]-1] || num[s[i]-1] ==  c[i] + '0') {
            num[s[i]-1] = c[i] + '0';
            nums[s[i]-1] = false;
        } else {
            num = "-1";
            break;
        }
    }

    if(n > 1 && num[0] == '0') {
        num[0] = '1';
    }

    cout << num << endl;

}
int main()
{
    solve1();
}
