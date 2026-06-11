#include <iostream>
using namespace std;

int p[5005], c[5005], n, k;
long long ans = -2e15;

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    for(int i = 1; i <= n; i++)
        cin >> c[i];

    for(int i = 1; i <= n; i++) {
        int cycleSize = 0;
        long long cycleSum = 0;
        int v = i;
        while(true) {
            cycleSize++;
            cycleSum += c[v];
            v = p[v];
            if(v == i) break;
        }

        int cnt = 0;
        long long sum = 0;
        while(true) {
            cnt++;
            sum += c[v];

            if(cnt > k) break;
            int completeCycles = (k-cnt)/cycleSize;
            long long score = sum + max(0LL, cycleSum)*completeCycles;
            ans = max(ans, score);

            v = p[v];
            if(v == i) break;
        }
    }

    cout << ans;
}
