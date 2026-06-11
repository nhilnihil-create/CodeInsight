#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    ll N;
    cin >> N;
    ll i;
    
    vector<ll> A (N+1, 0);
    vector<ll> B (N+1, 0);
    vector<ll> C (N+1, 0);
    vector<ll> D (N+1, 0);

    for(i=1;i<=N;i++){
        ll bi;
        cin >> bi;
        B[bi] += 1;
        A[i] = bi;
    }

    ll D_sum = 0;
    for(i=1;i<=N;i++){
        ll count_1;
        ll count_0;
        count_1 = B[i] - 1;
        count_0 = B[i];
        C[i] = count_1 * (count_1-1) / 2;
        D[i] = count_0 * (count_0-1) / 2;
        D_sum += D[i];
    }


    for(i=1;i<=N;i++){
        cout << D_sum - D[A[i]] + C[A[i]] << endl;    
    }

    return 0;
}
