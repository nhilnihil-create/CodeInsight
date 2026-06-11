#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
typedef long long int ll;
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    rep(i, n + 1)
        cin >> a[i];
    rep(i, n)
        cin >> b[i];

    long cnt = 0;
    long mod = 0;
    rep(i, n + 1) {
        if (0 > a[i] - b[i] - mod) {
            //全員a[i]倒せる
            cnt += a[i];

            //今のが倒さないといけない量
            mod = a[i] - mod;

            if (0 > mod)
                //前のが全員倒してくれたら今のはフル
                mod = b[i];
            else
                //前のが力尽きたら今も使って残りは繰越
                mod = b[i] - mod;

        }            
        else {
            //b[i]+繰越だけ倒せる
            cnt += b[i] + mod;

            //次への繰越無し
            mod = 0;
        }
    }

    cout << cnt << endl;

    return 0;
}