#include <iostream>
using namespace std;
typedef long long llong;
llong w[100010];
int main() {
    int n,k,count = 1,num = 1;
    llong sum = 0,max = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        sum += w[i];
    }

    llong ans = sum / k + (sum % k == 0?0:1);

    while (count <= n) {
        count = 1,num = 1,max = 0;
        for (int i = 0; i < n; i++) {
            if (w[i] > ans) {
                ans = w[i] - 1;
                break;
            }else {
                max += w[i];
                if (max > ans) {
                    max = w[i] ;
                    num++;
                }
                if (num > k) {
                    break;
                }
                count++;
            }
        }
        if (count != n+1) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
