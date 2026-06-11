#include <iostream>
#include <queue>
using namespace std;

long long n, a[200005], b[200005], m, k, ans, sumA[200005], sumB[200005];

long long bs(long long t) {
    if(t < sumB[1]) return 0;
    if(t >= sumB[m]) return m;

    long long l = 1, r = m;
    while(l <= r) {
        long long mid = (l+r)/2;
        if(sumB[mid] <= t && sumB[mid+1] > t) return mid;
        else if(sumB[mid] <= t) l = mid+1;
        else r = mid-1;
    }
    return -1;
}

int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sumA[i] = sumA[i-1]+a[i];
    }
    for(int j = 1; j <= m; j++) {
        cin >> b[j];
        sumB[j] = sumB[j-1]+b[j];
    }

    for(long long i = 0; (i <= n) && (sumA[i] <= k); i++) {
        long long t = k-sumA[i];
        long long pos = bs(t);
        ans = max(ans, i+pos);
    }
    cout << ans;
}
