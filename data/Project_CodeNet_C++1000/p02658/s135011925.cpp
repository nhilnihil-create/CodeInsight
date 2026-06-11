#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];
    long long ans = 1;
    long long v = 1;
    for(int i = 0; i < 18; ++i) v *= 10;
    sort(A.begin(), A.end());
    for(int i = 0; i < N; ++i){
        if(A[i] == 0){
            ans = 0;
            break;
        }
        else if(v/ans < A[i]){
            ans = -1;
            break;
        }
        else ans *= A[i];
    }
    cout << ans << endl;
    return 0;
}