#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int x;
    cin >> x;

    long long int deposit = 100;
    int ans = 0;
    while(deposit < x){
        deposit += deposit / 100;
        ans += 1;
    }
    cout << ans << endl;
    return 0;
}