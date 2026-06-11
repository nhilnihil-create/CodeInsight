#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    long long N;
    cin >> N;
    long long n_max = (int)ceil(sqrt(N));
    long long x = 1;
    long long y = N;
    long long ans = (N-1);
    for(int i=1; i<=n_max; i++){
        if(N%i == 0){
            long long val = N/i;
            if(ans > (i-1)+(val-1)){
                ans = (i-1)+(val-1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}