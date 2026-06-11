#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>

vi A;

long solve_move(int mod, int N){
    vi A_MOD(N);    
    int move = 0;
    long mod_sum = 0;
    REP(i, 0, N) {
        A_MOD[i] = A[i] % mod;
        mod_sum += A_MOD[i];
    }
    
    sort(A_MOD.rbegin(), A_MOD.rend());
    REP(i, 0, mod_sum/mod){
        move += mod - A_MOD[i];
       // cout<<mod<<" "<<A_MOD[i]<<endl;
    }
    return move;
}

int main() {
    int N, K;
    cin>>N>>K;
    long sum = 0;
    A.resize(N);
    REP(i, 0, N){
        cin >> A[i];
        sum += A[i];
    }
    int max_GCD = 0;
    int root_sum = pow(sum, 0.5);
    REP(i, 1, root_sum + 1){
        if(sum % i == 0){
            int move = solve_move(i, N);

            if(move <= K && max_GCD < i) max_GCD = i;
            //cout<<move<<" "<<i<<endl;
            move = solve_move(sum/i, N);
            if(move <= K && max_GCD < sum / i) max_GCD = sum / i;
             //cout<<move<<" "<<i<<endl;
        }
    }
    cout << max_GCD << endl;
}
