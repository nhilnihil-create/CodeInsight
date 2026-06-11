#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<long long, long long> P;
int main(){
    long long N, K;
    cin >> N >> K;
    vector<long long> A(N), F(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> F[i];
    sort(A.begin(), A.end());
    sort(F.begin(), F.end());
    long long ub = 1e18, lb = -1;
    while(ub - lb > 1){
        long long mid = (ub + lb) / 2;
        long long cnt = 0;
        for(int i = 0; i < N; i++){
            if(mid < A[i] * F[N - 1 - i]) cnt += A[i] - mid / F[N - 1 - i];
        }
        if(cnt > K) lb = mid;
        else ub = mid;
    }
    cout << ub << endl;
}