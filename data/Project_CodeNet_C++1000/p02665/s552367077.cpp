#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1ll << 60
     
using namespace std;
typedef long long ll;
typedef pair<int, int> pp;
     
int main(void) {
    int num, i;
    ll k = 1, ans = 0;
    cin >> num;
    num++;
    vector<ll> d(num), f(num);
    for(i = 0; i < num; i++)
        cin >> d[i];
    for(i = 0; i < num; i++)
        f[i]=d[i];
    for (i = num - 2; i >= 0; i--)
        f[i] += f[i + 1];
    for(i = 0; i < num; i++) {
        if (k < d[i]) {
            ans = -1;
            break;
        }
        ans += min(k, f[i]);
        k -= d[i];
        k <<= 1;
        if (k > INF)
            k = INF;
    }
    cout << ans << "\n";
    return 0;
}