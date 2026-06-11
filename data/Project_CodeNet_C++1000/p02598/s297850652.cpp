#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N,K; cin >> N >> K;
    vector<int> A(N);
    for(int i=0; i < N; ++i) cin >> A[i];
    
    int left = 0;
    int right = *max_element(A.begin(), A.end());

    while (right - left > 1){
        int mid = (left + right) /2;
        long long jk = 0;
        for(int j=0; j < N; j++){
            jk += A[j] / mid - 1;
            if(A[j] % mid != 0) jk++;
        }
        if(jk <= K) right = mid;
        else left = mid;
    }

    cout << right <<endl;
}
