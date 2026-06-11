#include<bits/stdc++.h>
using namespace std;

int main(){
    int K, N;
    cin >> K >> N;
    vector<int> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];
    sort(A.begin(), A.end());
    int max_distance = 0, buf = 0;
    for(int i = 0; i < N; ++i){
        if(i == 0) max_distance = K-A[N-1] + A[i];
        else max_distance = max(max_distance, A[i]-A[i-1]);
    }
    cout << K-max_distance << endl;
    return 0;
}