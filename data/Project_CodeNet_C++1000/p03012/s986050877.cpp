
#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int goukei = 0;
    vector<int>W(N);
    for(int i = 0; i < N; i++) {
        cin >> W[i];
        goukei += W[i];
    }
    int ans = 1e7;
    for(int i = 0; i < N; i++) {
        int cnt = 0;
        for(int j = 0; j < i; j++) {
            cnt += W[j];
        }
        ans = min(ans,abs((goukei-cnt)-cnt));
    }
    cout << ans << endl;
}

