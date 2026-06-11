#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,M; 
    cin >> N >> M;
    int H[100010],MA[100010];

    for(int i=1; i<=N; i++){
        cin >> H[i];
        MA[i] = 0;
    }

    for(int i=0; i<M; i++){
        int a,b;
        cin >> a >> b;
        MA[a] = max(MA[a],H[b]);
        MA[b] = max(MA[b],H[a]);
    }
    int ans = 0;
    for(int i=1; i<=N; i++){
        if(H[i] > MA[i]) {
            ans++;
        }
    }
    cout << ans << endl;

}