#include <bits/stdc++.h>

using namespace std;

long long n, k;

int main(){
    cin >> n >> k;
    cin.ignore();

    if(n <= 0) return 0;
    if(k <= 1) return 0;

    long long kk = k;
    int cnt = 1;
    while(n >= kk){
        ++cnt;
        kk *= k;
        //printf("%lld\n", kk);
    }
    cout << cnt << endl;
    return 0;
}