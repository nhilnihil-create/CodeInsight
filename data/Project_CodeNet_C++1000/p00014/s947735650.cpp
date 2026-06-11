#include <bits/stdc++.h>

using namespace std;

long long solve(int a, int b){

    long long ret = 1;
    while(b--) ret *= a;
    return ret;

}

int main(){

    int d;

    while(cin >> d){

        long long ans = 0;

        for(int i = 1; i < 600 / d; ++i){
            ans += solve(d * i, 2) * d;
        }

        cout << ans << endl;

    }

}