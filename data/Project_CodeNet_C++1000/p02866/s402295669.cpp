#include <iostream>
#include <vector>

using namespace std;
constexpr int64_t MOD =   998'244'353;

int main(void) {
    int N;
    cin >> N;
    vector<int> D(N);
    vector<int> num(N);
    for(int i=0; i<N; i++) {
        cin >> D[i];
        num[D[i]]++;
    }

    int64_t ans = 1;
    if(D[0] != 0 || num[0] != 1) {
        ans = 0;
    } else {
        for(int i=0; i<N; i++) {
            for(int j=0; j<num[i+1]; j++) {
                ans = (ans*num[i]) % MOD;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
