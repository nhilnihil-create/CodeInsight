#include <iostream>
#include <algorithm>
#include <fstream>
#include <utility>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define IO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef long double ld;

using namespace std;
const ll INF = 1e18;
const int mod = 1e4, N = 1e5 + 5, inf = 1e9;

int main()
{
    IO
    int n, arr[N], brr[N];
    ll ans = 0;
    cin >> n;
    for(int i = 0; i <= n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
        cin >> brr[i];
    for(int i = 0; i < n; i++)
    {
        int tmp = 0;
        tmp = min(brr[i], arr[i]);
        brr[i] -= tmp;
        arr[i] -= tmp;
        ans += tmp;
        tmp = min(brr[i], arr[i + 1]);
        brr[i] -= tmp;
        arr[i + 1] -= tmp;
        ans += tmp;
    }
    cout << ans << '\n';
    return 0;
}