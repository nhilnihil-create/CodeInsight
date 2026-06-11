#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N,M;
    cin >> N >> M;
    int ans = N;
    for(int i = 0 ; i < M ; i++){
        int tmp;
        cin >> tmp;
        ans -= tmp;
    }
    if(ans < 0) cout << -1 << endl;
    else cout << ans << endl;
    
}