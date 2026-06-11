#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (n); i++)


int main(){
    int M = 998244353;
    int N;
    cin >> N;

    long long D[N];
    map<int, int> m;
    for (int i = 0; i < N; i++) {
        cin >> D[i];
        m[D[i]]++;
    }
    long long res = 0;
    if (m[0] != 1) {
        res = 0;
    }else{
        res = 1;
        for (int i = 1; i < N; i++) {
            res *= m[D[i] - 1];
            res %= M;
        }
    }
 
    cout << res << endl;
    return 0;
}