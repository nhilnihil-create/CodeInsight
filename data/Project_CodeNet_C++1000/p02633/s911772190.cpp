#include <bits/stdc++.h>
using namespace std;


void solve(long long X){
    int dir = 0, cnt = 0;
    do
    {
        dir += X;
        cnt++;
    } while (dir % 360 != 0);
    cout << cnt << endl;
}

int main(){
    long long X;
    scanf("%lld",&X);
    solve(X);
    return 0;
}
