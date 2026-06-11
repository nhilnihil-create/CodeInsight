#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int k, n;
    cin >> k >> n;
    vector<int> A(n);
    
    for(int i = 0; i < n; i++)
        cin >> A[i]; 

    int m = max(A[0], A[0] + k - A[n-1]);
    
    for(int i = 1; i < n - 1; i++)
        m = max(m, A[i+1] - A[i]);
    
    int ans = k - m;
    
    cout << ans <<endl;
    
}