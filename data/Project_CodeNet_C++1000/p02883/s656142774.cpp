#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)
vector<long> A, F;
bool isPossible(long K, long mid){
    long sum_cost = 0;
    long ideal;
    int N = A.size();
    REP(i, 0, N){
        if(A[i] * F[i] > mid){
            ideal = mid / F[i];
            sum_cost += A[i] - ideal;
        }        
    }
    return (sum_cost <= K);
}

long binary_search(long K, long cnt){
    long left = -1; long right = cnt;
    while(right - left > 1){
        long mid = (right + left) /2;
        if(isPossible(K, mid)) right = mid;
        else left = mid;
    }
    return right;
}

int main() {
    long N, K;
    cin>>N>>K;
    long biggest = 1000000000000000000;
    A.resize(N); F.resize(N);
    REP(i, 0, N) cin>> A[i];
    REP(i, 0, N) cin>> F[i];
    sort(A.begin(), A.end());
    sort(F.rbegin(), F.rend());
    long ans = binary_search(K, biggest);
    cout << ans << endl;
}