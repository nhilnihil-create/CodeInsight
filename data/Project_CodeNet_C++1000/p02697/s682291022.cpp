#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N, M;
    cin >> N >> M;
    ll head = 2 * (M/2) + 1;
    if(M % 2 == 0){
        rep(i, 1, M/2 + 1){
            cout << i << " " << head << endl;
            head--;
        }
        head = 2 * (M/2) + 1 + 2 * (M)/2;
        rep(i, 1, (M)/2 + 1){
            cout << i + 2 * (M/2) + 1 << " " << head << endl;
            head--;
        }
    }else{
        rep(i, 1, M/2 + 1){
            cout << i << " " << head << endl;
            head--;
        }
        head = 2 * (M/2) + 1 + 2 * (M+1)/2;
        rep(i, 1, (M+1)/2 + 1){
            cout << i + 2 * (M/2) + 1 << " " << head << endl;
            head--;
        }
    }
    return 0;
}