#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    
    long long int i, N, ans;
    cin >> N;
    ans = 0;
    
    vector< int > A(N, 0);
    
    for (i = 0; i < N; i++){
        cin >> A[i];
    }
    
    sort(A.begin(), A.end(), greater<int>());

    for (i = 1; i < N; i++){
        ans += A[i / 2];
    }

    cout << ans << "\n";

    return 0;
}

