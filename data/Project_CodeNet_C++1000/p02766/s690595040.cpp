#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int func(int N, int K){
    int ans = 1;
    while(1){
        if(N / K > 0){
            ans++;
            N /= K;
        }else{
            break;
        }
    }
    return ans;
}
int main(){
    int N, K;
    cin >> N >> K;
    cout << func(N, K) << endl;
    return 0;
}