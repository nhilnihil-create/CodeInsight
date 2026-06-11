#include<bits/stdc++.h>
using namespace std;

int main(){
    int M,D;
    cin >> M >> D;
    int ans = 0;
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= D; j++) {
            int X = j%10;
            int Y = j/10;
            if(X >= 2 && Y >= 2) {
                if(X*Y == i) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}

