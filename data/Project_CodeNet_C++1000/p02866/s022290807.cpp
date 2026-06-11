#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;
constexpr int64_t MOD =   998'244'353;

int main(void) {
    int N;
    cin >> N;
    vector<int> D(N);
    for(int i=0; i<N; i++) {
        cin >> D[i];
    }
    if(D[0] != 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<int64_t> num(N);
    for(int i=0; i<N; i++) {
        num[D[i]]++;
    }
    if(num[0] != 1) {
        cout << 0 <<endl;
        return 0;
    }
    int64_t ans = 1;
    int max = *max_element(D.begin(), D.end());
    for(int i=0; i<max; i++) {
        for(int j=0; j<num[i+1]; j++) {
            ans = (ans*num[i]) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}