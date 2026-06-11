#include<bits/stdc++.h>
using namespace std;


int main(){
    int64_t N, K;
    cin >> N >> K;
    int64_t cnt = 0;
    for(int i=K; i<=N+1; i++){
        cnt += (N - i + 1) * i + 1;
        cnt %= (int64_t)pow(10, 9) + 7;
    }
    cout << cnt << endl;
}