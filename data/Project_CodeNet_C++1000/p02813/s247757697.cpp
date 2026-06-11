#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define PI acos(-1)
#define fs first
#define sc second
#define debug freopen("1.in", "r", stdin), freopen("1.out", "w", stdout);
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX = 0x7fffffff;
const int MIN = 0x80000000;
const ll maxn = 1e6 + 10;

int N, arr[10], a[10], b[10], cnt, k, m, bg, ed;

int main() {
    ios;
    cin >> N;
    for (int i = 1; i <= N; i ++){
        cin >> arr[i];
        a[i] = arr[i];
    }
    for (int i = 1; i <= N; i ++)cin >> b[i];
    sort(arr + 1, arr + 1 + N);
    cnt = 0;
    do{
        cnt++;
        k = 0;
        for (int i = 1; i <= N; i ++)
            if(arr[i] != a[i])
                break;
            else k = i;
       if (k == N) bg = cnt;
        m = 0;
        for (int i = 1; i <= N; i ++)
            if(arr[i] != b[i])
                break;
            else m = i;
        if(m == N) ed = cnt;
    }while(next_permutation(arr + 1, arr + 1 + N));
    cout << abs(bg - ed) << '\n';
    return 0;
}