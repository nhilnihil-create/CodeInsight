#include <iostream>
#include <algorithm>
#include <queue>
#define N 300007
using namespace std;
typedef long long ll;
int a[N], prefix[N];
vector<int> b;

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, now;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> now;
        a[now]++;
    }
    for (int i = 0; i <= n; i++)
        if (a[i])
            b.push_back(a[i]);
    sort(b.begin(), b.end());
    prefix[0] = b[0];
    for (int i = 1; i < b.size(); i++) {
        prefix[i] = prefix[i - 1] + b[i];
    }
    
    /* TLE
    sort(a, a + n + 1);
    for (int j = 1; j <= n; j++) {
        priority_queue<int, vector<int>, greater<>> q;
        int tot = 0, i;
        for (i = n; i > n - j; i--)
            q.push(a[i]);
        for (; i > 0; i--) {
            tot = q.top();
            q.pop();
            q.push(a[i] + tot);
        }
        cout << q.top() << "\n";
    }
    */
    
    //bisearch the answer
    for (int k = 1; k <= n; k++) {
        int l = 0, r = n / k + 1; //枚举操作次数
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (m == 0)
                break;
            int id = (int)(lower_bound(b.begin(), b.end(), m) - b.begin());
            int km = (int)(b.size() - id);
            if (id != 0) //很关键，把m=0的情况一同屏蔽，因为m=0时，id一定为0
                km += prefix[id - 1] / m;
            if (km >= k) {
                l = m;
            }
            else r = m;
        }
        cout << l << "\n";
    }
    
    return 0;
}