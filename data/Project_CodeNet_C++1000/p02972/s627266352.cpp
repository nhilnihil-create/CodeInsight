#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    int N, cnt;
    cin >> N;
    vector<int> data(N);
    vector<int> balls(N, 0);
    rep(i, N){
        cin >> data[i];
    }
    cnt = 0;
    for(int i = N; i >= 1; i--){
        int curTotal;
        curTotal = 0;
        int ref = 1;
        while(ref*i <= N){
            curTotal += balls[i * ref - 1];
            ref++;
        }
        if(curTotal % 2 != data[i - 1]){
            balls[i - 1] = 1;
            cnt++;
        }
    }
    cout << cnt << endl;
    rep(i, N){
        if(balls[i] == 1){
            cout << i+1 << " ";
        }
    }
    cout << endl;
    return 0;
}
