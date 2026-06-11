#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll>A(N);
    int flagN = 0; // 0なら全部0以上
    int flagP = 0; // 0なら全部0以下
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if(A[i] < 0) flagN = 1;
        if(A[i] > 0) flagP = 1;
    }

    ll M = 0;
    if(flagN == 0){
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
                A[0] = A[0] - A[i];
            }
            cout << A[1] << " " << A[0] << endl;
        }else{
            for (int i = 1; i < N; ++i) {
                if(i != x){
                    cout << A[x] << " " << A[i] << endl;
                    A[x] = A[x] - A[i];
                }
            }
            cout << A[0] << " " << A[x] << endl;
        }
    }else if(flagP == 0){
        int x = 0; // A[x] は絶対値最小
        M = M - A[0];
        for (int i = 1; i < N; ++i) {
            if(A[x] < A[i]) x = i;
            M = M - A[i];
        }
        M = M + (2 * A[x]);
        cout << M << endl;

        for (int i = 0; i < N; ++i) {
            if(i != x){
                cout << A[x] << " " << A[i] << endl;
                A[x] = A[x] - A[i];
            }
        }
        /*
        if(x == 0){
            for (int i = 2; i < N; ++i) {
                cout << A[1] << " " << A[i] << endl;
                A[1] = A[1] + A[i];
            }
            cout << A[0] << " " << A[1] << endl;
        }else{
            for (int i = 1; i < N; ++i) {
                if(i != x){
                    cout << A[0] << " " << A[i] << endl;
                    A[0] = A[0] + A[i];
                }
            }
            cout << A[x] << " " << A[0] << endl;
        }
         */
    }else{
        int firstP = -1;
        int firstN = -1;
        for (int i = 0; i < N; ++i) {
            M = M + abs(A[i]);
            if(firstP == -1 && A[i] > 0) firstP = i;
            if(firstN == -1 && A[i] < 0) firstN = i;
        }
        cout << M << endl;
        for (int i = 0; i < N; ++i) {
            if(A[i] > 0 && i != firstP){
                cout << A[firstN] << " " << A[i] << endl;
                A[firstN] = A[firstN] - A[i];
            }
            if(A[i] <= 0 && i != firstN){
                cout << A[firstP] << " " << A[i] << endl;
                A[firstP] = A[firstP] - A[i];
            }
        }
        cout << A[firstP] << " " << A[firstN] << endl;
    }
    return 0;
}