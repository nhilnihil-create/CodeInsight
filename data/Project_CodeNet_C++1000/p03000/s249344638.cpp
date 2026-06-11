#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,X;
    cin >> N >> X;
    vector<int>L(N);
    int ans = 0;
    vector<int>cnt(N+1);
    cnt[0] = 0;
    for(int i = 0; i < N; i++) {
        cin >> L[i];
        cnt[i+1] = cnt[i]+L[i];
    }
    for(int i = 0; i <= N; i++) {
        if(cnt[i] <= X) {
            ans++;
        }
        else {
            break;
        }
    }
    cout << ans << endl;
}