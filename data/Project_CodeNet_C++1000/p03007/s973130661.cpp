#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll>A(N);
    int flagN = -1; // -1なら全部0以上, 0以上なら A[i] < 0
    int flagP = -1; // -1なら全部0以下, 0以上なら A[i] > 0
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if(A[i] < 0) flagN = i;
        if(A[i] > 0) flagP = i;
    }

    ll M = 0;
    if(flagN == -1){
        int x = 0; // A[x] は絶対値最小
        M = A[0];
        for (int i = 1; i < N; ++i) {
            if(A[x] > A[i]) x = i;
            M += A[i];
        }
        M = M - (2 * A[x]);
        cout << M << endl;
        if(x == 0){
            for (int i = 2; i < N; ++i) {
                cout << A[0] << " " << A[i] << endl;
                A[0] -= A[i];
            }
            cout << A[1] << " " << A[0] << endl;
        }else{
            for (int i = 1; i < N; ++i) {
                if(i != x){
                    cout << A[x] << " " << A[i] << endl;
                    A[x] -= A[i];
                }
            }
            cout << A[0] << " " << A[x] << endl;
        }
    }else if(flagP == -1){
        int x = 0; // A[x] は絶対値最小
        M -= A[0];
        for (int i = 1; i < N; ++i) {
            if(A[x] < A[i]) x = i;
            M -= A[i];
        }
        M = M + (2 * A[x]);
        cout << M << endl;

        for (int i = 0; i < N; ++i) {
            if(i != x){
                cout << A[x] << " " << A[i] << endl;
                A[x] -= A[i];
            }
        }
    }else{
        // 正も負もある場合
        for (int i = 0; i < N; ++i) {
            M += abs(A[i]);
        }
        cout << M << endl;

        for (int i = 0; i < N; ++i) {
            if(A[i] >= 0 && i != flagP){
                cout << A[flagN] << " " << A[i] << endl;
                A[flagN] -= A[i];
            }
        }
        for (int i = 0; i < N; ++i) {
            if(A[i] < 0){
                cout << A[flagP] << " " << A[i] << endl;
                A[flagP] -= A[i];
            }
        }
    }
    return 0;
}