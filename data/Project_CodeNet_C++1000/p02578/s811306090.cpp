#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    
    int i, N;
    cin >> N;
    
    long long int A[N], max, sum;
    max = 0;
    sum = 0;
    
    for ( i = 0; i < N; i++ ){
        cin >> A[i];
        
        if (A[i] < max){
            sum += (max - A[i]);
        
        } else {
            max = A[i];
        }
    }
    
    cout << sum << "\n";
    
    return 0;
}

