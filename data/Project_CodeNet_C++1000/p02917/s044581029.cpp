#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    int N;
    cin >> N;
    int B[N-1], A[N];
    for(int i=0; i<N-1; i++) cin >> B[i];
    A[0] = B[0];

    for(int i=0; i<N-1; i++) {
        A[i+1] = B[i];
        if(A[i] > B[i]) {
            A[i] = B[i];
        }
    }

    ll count = 0;
    for(int i=0; i<N; i++) count += A[i];
    cout <<count << endl;
}