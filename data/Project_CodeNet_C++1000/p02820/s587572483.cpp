#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 1000000000000000000;
const double PI = acos(-1);

// 入力numが素数かどうか判定する関数
bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

int main()
{
    int n, k, r, s, p;
    string t;
    cin >> n >> k >> r >> s >> p >> t;

    string me;
    ll ans = 0;
    rep(i, n) {
        if (i < k) {
            if (t[i] == 'r') {
                me += 'p';
                ans += p;
            }
            else if (t[i] == 's') {
                me += 'r';
                ans += r;
            }
            else {
                me += 's';
                ans += s;
            }
        }
        else {
            if (t[i] == 'r') {
                if (me[i - k] == 'p') {
                    if (i >= (n - k)) {
                        me += 'r';
                    }
                    else if (t[i + k] == 'r') {
                        me += 'r';
                    }
                    else if (t[i + k] == 's') {
                        me += 's';
                    }
                    else {
                        me += 'r';
                    }
                }
                else {
                    me += 'p';
                    ans += p;
                }
            }
            if (t[i] == 's') {
                if (me[i - k] == 'r') {
                    if (i >= (n - k)) {
                        me += 's';
                    }
                    else if (t[i + k] == 'r') {
                        me += 's';
                    }
                    else if (t[i + k] == 's') {
                        me += 's';
                    }
                    else {
                        me += 'p';
                    }
                }
                else {
                    me += 'r';
                    ans += r;
                }
            }
            if (t[i] == 'p') {
                if (me[i - k] == 's') {
                    if (i >= (n - k)) {
                        me += 'p';
                    }
                    else if (t[i + k] == 'r') {
                        me += 'r';
                    }
                    else if (t[i + k] == 's') {
                        me += 'p';
                    }
                    else {
                        me += 'p';
                    }
                }
                else {
                    me += 's';
                    ans += s;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}