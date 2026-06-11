#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, K; cin >> N >> K;
    int mx = (N-1)*(N-2)/2;
    if(K > mx){
        cout << -1 << endl;
    } else {
        int tuika = mx - K;
        cout << N-1 + tuika << endl;
        for (int i = 2; i <= N; i++){
            cout << 1 << " " << i << endl;
        }
        int cnt = 0;
        bool ok = false;
        for (int i = 2; i <= N-1; i++){
            for (int j = i+1; j <= N; j++){
                if(cnt == tuika){
                    ok = true;
                    break;
                }
                cout << i << " " << j << endl;
                cnt++;
            }
            if(ok)break;
        }
    }
    return 0;
}