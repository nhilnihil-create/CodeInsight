#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    
    long long int i, N, K, min, max, mid, cut;
    cin >> N >> K;
    
    vector<long long int> A(N);
    
    for (i = 0; i < N; i++){
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    if (K == 0){
        cout << A[N - 1] << "\n";
        return 0;
    }
    
    min = 0;
    max = A[N - 1];
    
    while(max - min > 1){
        
        mid = (min + max) / 2;
        cut = 0;
        
        for (i = 0; i < N; i++){
            cut += (A[i] - 1) / mid;
        }
        
        if (cut > K){
            min = mid;
        } else {
            max = mid;
        }
        
    }
    
    cout << max << "\n";

    return 0;
}

