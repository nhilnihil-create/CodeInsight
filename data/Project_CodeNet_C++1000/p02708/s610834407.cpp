#include<bits/stdc++.h>
using namespace std;
int main(){
    int64_t N = 1000000007;
    int64_t n,k;
    cin >> n >> k;
    
    int64_t ans=0;
    for(int64_t i=k; i<=n+1; i++){
        int64_t inf = i*(i-1)/2;
        int64_t sup = (2*n-i+1)*i/2;
        ans = (ans + ((sup-inf)+1))%N;
    }
    cout << ans << endl;
}
