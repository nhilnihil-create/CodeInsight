#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, D;
    cin >> N >> D;
    int res =0 ;
    long long dis = (long long)D * D;
    for (int i = 0; i < N; i++){
        long long X, Y;
        cin >> X >> Y;
        if (X * X + Y * Y <= dis) res++;
    }
    cout << res << endl;
    return 0;
}