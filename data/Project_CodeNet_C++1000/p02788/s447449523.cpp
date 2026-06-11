#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N, D, A;
    cin >> N >> D >> A;

   vector<pair<int, int>> p;
    for(int i=0; i<N; i++){
        int x, h;
        cin >> x >> h;
        p.push_back(make_pair(x, h));
    }

    sort(p.begin(), p.end());
    int H[N], X[N];
    for(int i=0; i<N; i++){
        X[i] = p[i].first;
        H[i] = p[i].second;
    }

    long sum[N+2];
    fill(sum, sum+N+2, 0);

    long ans = 0;
    for(int i=1; i<=N; i++){
        sum[i] += sum[i-1];

        int x = X[i-1];
        int h = H[i-1];

        if(h - sum[i]*A <= 0) continue;
        long add = ((h-sum[i]*A)-1)/A + 1;
        sum[i] += add;
        ans += add;

        int it = lower_bound(X, X+N, x + 2*D+1) - X;
        sum[it+1] -= add;
    }

    cout << ans << endl;

    return 0;
}