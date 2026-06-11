#include <bits/stdc++.h>
using namespace std;

int main(){
    int64_t K, N, ans;
    cin >> K;
    N = 7;
    ans = -1;
    for(int i = 0; i < 1000000; i++){
        if(N % K == 0){
            ans = i + 1;
            break;
        }
        else
            N = (N * 10 + 7) % K;
      
    }
    cout << ans << endl;
}