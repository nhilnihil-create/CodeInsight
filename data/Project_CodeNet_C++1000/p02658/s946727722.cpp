#include <bits/stdc++.h>

using namespace std;

int main() {
    int N = 0;
    unsigned long long A = 0, ans = 1;
    vector<unsigned long long > vec;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A;
        vec.push_back(A);
    }

    sort(vec.begin(), vec.end());

    unsigned long long z = pow(10, 18);
    for (unsigned long long x:vec) {
        if (x == 0) {
            cout << 0 << endl;
            return 0;
        } else {
            if(x<=z/ans){
                ans*=x;
            }else{
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
}