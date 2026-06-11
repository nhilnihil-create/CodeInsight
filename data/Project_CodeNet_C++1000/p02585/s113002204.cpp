#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

ll solver(int N, int K, vector<int> P, vector<ll> C){
    ll ans = -1 * INF;
    rep(i, N){
        int now = i;
        ll score = 0;
        int cnt = 0;
        rep(j, K){
            now = P[now];
            score += C[now];
            ans = max(ans, score);
            cnt++;
            if(now == i){//一周してしまった
                if(score < 0)break;
                ll tmp = score;
                score = (K/cnt) * tmp;
                ans = max(ans, score);
                rep(k, K%cnt){
                    now = P[now];
                    score += C[now];
                    ans = max(ans, score);
                }

                score = (K/cnt - 1) * tmp;
                // cout << "score:" <<score << endl;
                ans = max(ans, score);
                rep(k, cnt){
                    now = P[now];
                    score += C[now];
                    ans = max(ans, score);
                }
                break;
            }
        }
    }
    return ans;
}

ll solver2(int N, int K, vector<int> P, vector<ll> C){
    ll ans = -1*INF;
    rep(i, N){
        int now = i;
        ll score = 0;
        rep(j, K){
            now = P[now];
            score += C[now];
            ans = max(ans, score);
        }
    }
    return ans;
}

int main(){
    int N, K; cin >> N >> K;
    vector<int> P(N);
    vector<ll> C(N);
    rep(i, N){
        int p; cin >> p;
        p--;
        P[i] = p;
    }
    rep(i, N)cin >> C[i];

    cout << solver(N, K, P, C) << endl;

    // random_device seed_gen;
    // mt19937_64 engine(seed_gen());
    // while(1){
    //     int N = engine() % 5 + 2;
    //     int K = engine() % (int)1e2 + 1;
    //     vector<int> P(N);
    //     rep(i, N) P[i] = i;
    //     rep(i, N){
    //         int j = engine()%N;
    //         if(P[i] == P[j]){
    //             i--;
    //             continue;
    //         }
    //         swap(P[i],P[j]);
    //     }
    //     vector<ll> C(N);
    //     rep(i, N){
    //         C[i] = engine() % (ll)1e3;
    //         int j = engine() % 2;
    //         if(j == 0)C[i] *= -1;
    //     }

    //     ll ans1 = solver(N, K, P, C);
    //     ll ans2 = solver2(N, K, P, C);
    //     if(ans1 != ans2){
    //         cout << N << " " << K << endl;
    //         rep(i, N) cout << P[i] << " ";
    //         cout << endl;
    //         rep(i, N) cout << C[i] << " ";
    //         cout << endl << endl;
    //         cout << "solver1:" << ans1 << endl;
    //         cout << "solver2:" << ans2 << endl;

    //         break;
    //     }else{
    //         cout << "OK!" << endl;
    //     }
        
    // }
    
    
    
}
