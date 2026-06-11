#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int64_t i=0; i<(int64_t)(n); i++)
#define all(v) v.begin(), v.end()
//e
int main(){

    int N, M; cin >> N >> M;

    if(N%2==1){
        int x=1, y=N-1;
        rep(i, M){
            cout << x << " " << y << endl;
            x++;
            y--;
        }
    }
    if(N%2==0){
        int x=1, y=N-1;
        rep(i, M){
            if(i==(N/2-1)/2) y--;
            cout << x << " " << y << endl;
            x++;
            y--;
        }
    }

    return 0;

}