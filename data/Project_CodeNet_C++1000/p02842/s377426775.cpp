#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
using namespace std;

int main(){
    int N;
    cin >> N;
    rep(i, 50000){
        if(floor(i*1.08) == N){
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;

    return 0;
}