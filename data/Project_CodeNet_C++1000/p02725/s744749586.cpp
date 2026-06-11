#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int, int>;
#define INF 1001001001
#define PI 3.14159265359
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repX(i, n , x) for (int i = (int)(x); i < (int)(n); ++i)
#define repB(i, n) for (int i = n; i >= 1; --i)
#define repBX(i, n , x) for (int i = (int)(n); i >= int(X); --i)
#define dup(x,y) (((x)+(y)-1)/(y))

int main() {
    int K,N;
    cin >> K >> N;
    vector<int> A(N);
    vector<int> dist(N);
    cin >> A[0];
    int MaxDist = 0;
    int MaxI = 0;
    repX(i,N,1){
        cin >> A[i];
        dist[i] = A[i]-A[i-1];
        if(MaxDist<dist[i]){
            MaxDist = dist[i];
            MaxI = i;
        }
    }
    dist[0] = A[0] + (K - A[N - 1]);
    if (MaxDist < dist[0])
    {
        MaxDist = dist[0];
        MaxI = 0;
    }
    int ans = 0;
    rep(i,N){
        if(i==MaxI)continue;
        ans += dist[i];
    }
    cout << ans << endl;

    return 0;
}