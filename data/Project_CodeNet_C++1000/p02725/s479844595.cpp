#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int main(void)
{
    int k, n; cin >> k >> n;
    queue<int> a;
    int _a;
    for (int i = 0; i < n; i++) 
    {
        cin >> _a;
        a.push(_a);
    }

    int ans = k;
    int d, s, t1, t2;
    for (int i = 0; i < n; i++)
    {
        s = a.front(); a.pop();
        t1 = a.front();
        t2 = a.back();
        d = min(t2 - s, k - (t1 - s));
        ans = min(ans, d);
        a.push(s + k);
    }
    cout << ans << endl;
}