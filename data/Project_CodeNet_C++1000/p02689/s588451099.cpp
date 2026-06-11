#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M, ans = 0;

    cin >> N >> M;
    
    int H[N], ma[N];

    for(int i=0; i < N; i++){
        cin >> H[i];
        ma[i] = 0;
    }

    for(int i=0; i < M; i++){
        int a, b;

        cin >> a >> b;

        ma[a-1] = max(ma[a-1], H[b-1]);
        ma[b-1] = max(ma[b-1], H[a-1]);
    }

    for(int i=0; i < N; i++){
        if(H[i] > ma[i]) ans++;
    }

    cout << ans << endl;


    return 0;
}