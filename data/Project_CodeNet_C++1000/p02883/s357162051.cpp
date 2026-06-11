#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<int> A(N),F(N);
    for (int i=0;i<N;i++) cin >> A[i];
    for (int i=0;i<N;i++) cin >> F[i];
    sort(A.rbegin(),A.rend()); //消化コストは降順
    sort(F.begin(),F.end()); //食べにくさは昇順
    //最小値Xが実現できるかを２分探索で求めるのを
    ll upper = 1e12;
    ll lower = -1;
    ll mid;
    while (upper - lower > 1){
        ll mid = (upper + lower)/2;
        ll m =0;
        for (int i=0;i<N;i++){
            m += max(0LL, A[i] - mid/F[i]);
        }
        if (m > K) {
            lower = mid;
        } else {
            upper = mid;
        }
    }
    cout << upper << endl;
    

    return 0;
}