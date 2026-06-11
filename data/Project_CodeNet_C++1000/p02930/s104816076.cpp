#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    int k = 0, tmpN = N;

    while(tmpN > 0){
        k++;
        tmpN /= 2;
    }

    for(int i = 1; i <= N; i++){
        for(int j = i + 1; j <= N; j++){
            int tmpi = i, tmpj = j;
            int cnt = 1;
            //cout << (tmpi ^ tmpj) << endl;
            while(((tmpi ^ tmpj) & 1) == 0){
                tmpi >>= 1;
                tmpj >>= 1;
                cnt++;
            }
            cout << cnt << " ";
        }
        cout << endl;
    }
}