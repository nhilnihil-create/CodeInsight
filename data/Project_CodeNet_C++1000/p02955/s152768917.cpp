#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    int N, K; cin >> N >> K;
    int sum = 0;
    int A[N]; rep(i, N){ cin >> A[i]; sum += A[i]; }

    vector<int> yakusuu;
    int lim = sqrt(sum);
    for(int i = 1; i <= lim; i++){
        if(sum % i == 0){
            yakusuu.push_back(i);
            yakusuu.push_back(sum/i);
        }
    }

    int ans = 1;
    rep(i, yakusuu.size()){
        int md = yakusuu[i];
        if(md <= ans) continue;

        int work_add[N];
        int work_sub[N];
        rep(j, N){
            work_add[j] = A[j] % md;
            work_sub[j] = md - work_add[j];
        }
        sort(work_add, work_add+N);
        sort(work_sub, work_sub+N);

        int acc_add = 0, acc_sub = 0;
        int idx_add = 0, idx_sub = 0;
        while(idx_add + idx_sub < N){
            if(acc_add <= acc_sub){
                acc_add += work_add[idx_add++];
            }
            else acc_sub += work_sub[idx_sub++];
        }
        if(acc_add <= K){
            ans = md;
            //cout << md << " is okay: " << acc_add << endl;
        }
    }
    cout << ans << endl;
    return 0;
}

//1 7 5 6 8 2 6 5
//5で割れるか
//1 2 0 1 3 2 1 0 -> 0 0 1 1 1 2 2 3
//                   2 3 3 4 4 4 5 5
//8で割れるか
//1 7 5 6 0 2 6 5 -> 0 1 2 5 5 6 6 7
//                   0 7 6 3 3 2 2 1