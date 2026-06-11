#include <iostream>
using namespace std;
int a[200006], b[200006], f[200006];
int main () {
    int N, M, K;
    cin >> N >> M >> K;
    for (int i=0; i<N; i++) {
        cin >> a[i];
    }
    for (int i=0; i<M; i++) {
        cin >> b[i];
    }
    int u=0, pt=0;
    for (int i=0; i<M; i++) {
        if (u+b[i]<=K) {
            u+=b[i];
            pt++;
            f[0]++;
        }
        else {
            break;
        }
    }
    int sum=0, ans=f[0];
    for (int i=1; i<=N; i++) {
        sum+=a[i-1];
        if (sum>K) {
            break;
        }
        for (int j=0; j<M; j++) {
            if (sum+u<=K) {
                f[i]+=pt;
                break;
            }
            else {
                if (pt<=0) {
                    break;
                }
                u-=b[pt-1];
                pt--;
            }
        }
        ans=max(ans,f[i]+i);
    }
    cout << ans << endl;
}
