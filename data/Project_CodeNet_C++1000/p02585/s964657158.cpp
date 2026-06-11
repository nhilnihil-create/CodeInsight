#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const ll INF = 1000000000000000;

int N,K; vi P; vector<ll> C;
void input()
{
    cin >> N >> K;
    P.resize(N); C.resize(N);
    for (int i = 0; i < N; ++i){ 
        cin >> P[i];
        P[i]--;
    }
    for (int i = 0; i < N; ++i) cin >> C[i];
}

void solve()
{
    vector<bool> is_checked(N,false);
    ll ma = -INF;
    for (int i = 0; i < N; ++i){
        if (is_checked[i]) continue;

        is_checked[i] = true;
        int next = P[i];
        vi loop; 
        loop.emplace_back(i);
        ll loop_sum = C[i];
        while (next != i){
            loop.emplace_back(next);
            loop_sum += C[next];
            is_checked[next] = true;
            next = P[next];
        }

        // cout << "group: ";
        // for (int j = 0; j < loop.size(); ++j) cout << loop[j]+1 << " ";
        // cout << "loop_sum: " << loop_sum << endl;

        for (int j = 0; j < loop.size(); ++j){
            ll sum; int move;
            if (loop_sum <= 0){
                sum = 0; 
                move = K;
            } else {
                sum = ((K / loop.size()) - 1) * loop_sum; 
                move = K % loop.size() + loop.size();
            }

            // cout << "sum: " << sum << " move: " << move << endl;

            ll ma_i = -INF; 
            next = P[loop[j]];
            while (next != loop[j] && move > 0){
                sum += C[next];
                --move;
                if (ma_i < sum){
                    ma_i = sum;
                }
                next = P[next];
            }
            if (next == loop[j] && move > 0){
                sum += C[next];
                --move;
                if (ma_i < sum){
                    ma_i = sum;
                }
                next = P[next];
            }
            while (next != loop[j] && move > 0){
                sum += C[next];
                --move;
                if (ma_i < sum){
                    ma_i = sum;
                }
                next = P[next];
            }

            // cout << loop[j]+1 << " " << ma_i << endl;
            
            ma = max (ma, ma_i);
        }
        // cout << endl;
    }

    cout << ma << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}