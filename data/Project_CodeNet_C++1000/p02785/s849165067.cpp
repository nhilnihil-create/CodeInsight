#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    int N, K;
    cin >> N >> K;

    if(N <= K) cout << 0 << endl;
    else{
        vector<int> H(N);
        for(int i = 0; i < N; i++) cin >> H.at(i);

        sort(H.begin(), H.end());
    
        int64_t sum=0;
        for(int i = 0; i < N-K; i++) sum += H.at(i);

        cout << sum << endl;
    }
}
