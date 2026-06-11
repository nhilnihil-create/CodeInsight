#include <iostream>
using namespace std;
int main()
{
    long long n, d, x, y, cnt = 0;
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &x, &y);
        cnt += (x*x + y*y <= d*d ? 1 : 0);
    }
    cout << cnt << endl;
    return 0;
}