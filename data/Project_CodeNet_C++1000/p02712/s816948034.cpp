#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N, res;
    res = 0;

    cin >> N;

    for(int i = 1; i <= N; i++){
        if(i % 3 != 0 && i % 5 != 0){
            res += i;
        }
    }

    cout << res << endl;

    return 0;
}