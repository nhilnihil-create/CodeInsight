#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    int N, P;
    string S;
    cin >> N >> P >> S;
    
    int64_t ans = 0;
    if(10 % P == 0) {
        for(int i=0; i<N; i++) {
            if((S[i]-'0') % P == 0) {
                ans += i+1;
            }
        }
    } else {
        vector<int64_t> v(P);
        int t = 0;
        int ten = 1;
        for(int i=0; i<N; i++) {
            t += (S[N-1-i]-'0') * ten;
            ten *= 10;
            t %= P;
            ten %= P;
            v[t]++;
        }
        for(auto e: v) {
            ans += e * (e-1) / 2;
        }
        ans += v[0];
    }

    cout << ans << endl;
    return 0;
}
