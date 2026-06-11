#include <iostream>
using namespace std;
int main(){
    long long l,r;
    cin >> l >> r;
    int ans = 3000;
    for(long long i = l; i < l+2019 && i < r; i++){
        for(long long j = i+1; j < l+2020 && j <=r; j++){
            int x = (i*j)%2019;
            ans = min(ans, x);
        }
    }
    cout << ans << endl;
    return 0;
}