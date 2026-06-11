#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(void){
    long long N;
    cin >> N;
    long long A[N];
    long long sum = 0;
    for(long long i = 0; i < N; i++){
        
        cin >> A[i];
        sum += A[i];    
            
    }
    
    long long left[N];
    long long right[N];
    long long accl = 0;
    for(long long i = 0; i < N; i++){
        
        accl += A[i];
        left[i] = accl;
        right[i] = sum - accl;
            
    }
    
    long long m =  LLONG_MAX ;
    
    for(long long i = 0; i < N; i++){
        
        m = min(m,abs(left[i]-right[i]));
    }
    
    cout << m << endl;
    
    
}
