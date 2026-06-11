#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;
int main(){
    long long N;
    cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    long long ans = 1;
    vector<long long> v(3, 0);
    for(int i = 0; i < N; i++){
        long long cnt = 0;
        int flag = -1;
        for(int j = 0; j < 3; j++){
            if(A[i] == v[j]) {
                cnt++;
                flag = j;
            }
        }
        if(cnt == 0){
            cout << 0 << endl;
            return 0;
        }
        ans = ans * cnt % MOD;
        v[flag]++;
    }
    cout << ans << endl;
}