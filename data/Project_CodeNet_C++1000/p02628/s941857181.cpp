#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, K, buf, ans = 0;
    cin >> N >> K;
    priority_queue<int, vector<int>, greater<int>> P;
    for(int i = 0; i < N; ++i){
        cin >> buf;
        P.push(buf);
    }
    for(int i = 0; i < K; ++i){
        ans += P.top();
        P.pop();
    }
    cout << ans << endl;
    return 0;
}