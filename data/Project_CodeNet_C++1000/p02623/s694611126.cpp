#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int fun(vector<long long int> X, int N){
    
    int size = X.size();
    int min = 0;
    int max = size - 1;
    int mid;
    
    if (X[min] > N) return 0;
    if (X[max] <= N) return (max + 1);
    
    while(max - min > 1){
        mid = (max + min) / 2;
        
        if (X[mid] > N){
            max = mid;
        } else {
            min = mid;
        }
    }
    
    if (X[max] > N){
        return (min + 1);
    } else {
        return (max + 1);
    }
    
    return 0;
}

int main(){
    
    int i, j, N, M, K, x, ans;
    cin >> N >> M >> K;
    
    vector< long long int > A(N, 0);
    vector< long long int > B(M, 0);
    vector< long long int > A_sum(N, 0);
    vector< long long int > B_sum(M, 0);
    
    for (i = 0; i < N; i++){
        cin >> A[i];
        if (i == 0){
            A_sum[i] = A[i];
        } else {
            A_sum[i] = A_sum[i - 1] + A[i];
        }
    }
    
    for (i = 0; i < M; i++){
        cin >> B[i];
        if (i == 0){
            B_sum[i] = B[i];
        } else {
            B_sum[i] = B_sum[i - 1] + B[i];
        }
    }
    
    x = fun(B_sum, K);
    
    if (x == 0){
        ans = fun(A_sum, K);
        cout << ans << "\n";
        return 0;
    }
    
    ans = x;
    
    for (i = 0; i < N; i++){
        
        int t = K - A_sum[i];
        if (t < 0) break;
        
        while(B_sum[x - 1] > t && x > 0) x--;
        
        if (i + 1 + x > ans) ans = i + 1 + x;
    }
    
    cout << ans << "\n";
    
    return 0;
}

