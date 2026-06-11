#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int wa = 0;
    vector<int>W(N);
    for(int i = 0; i < N; i++) {
        cin >> W[i];
        wa += W[i];
    }
    int ans = 10000000;
    for(int i = 0; i < N; i++) {
        int wawa = 0;
        for(int j = 0; j < i; j++) {
            wawa += W[j];
        }
        ans = min(ans,abs((wa-wawa)-wawa));
    }
    cout << ans << endl;
}

