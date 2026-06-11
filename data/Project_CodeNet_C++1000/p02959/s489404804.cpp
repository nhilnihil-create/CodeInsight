#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    int N; cin >> N;
    ll ans=0;
    int A[N+1],B[N];
    for(int i=0;i<N+1;i++) cin >> A[i];
    for(int i=0;i<N;i++) cin >> B[i];
    
    for(int i=0;i<N;i++){
        
        ans += min(A[i],B[i]);
        B[i] -= min(A[i],B[i]);
        if(B[i] > 0){ ans += min(A[i+1],B[i]); A[i+1] -= min(A[i+1],B[i]); }
    }
    
    cout << ans << endl;
} 