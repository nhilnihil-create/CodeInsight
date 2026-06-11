#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void) {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }

    while(K--) {
        if(count(A.begin(), A.end(), N) == N) break;
        vector<int> tmp(N+1);
        for(int i=0; i<N; i++) {
            tmp[max(0, i-A[i])]++;
            tmp[min(N, i+A[i]+1)]--;
        }
        tmp.pop_back();
        partial_sum(tmp.begin(), tmp.end(), A.begin());
    }

    for(auto e: A) {
        cout << e << endl;
    }
    return 0;
}
