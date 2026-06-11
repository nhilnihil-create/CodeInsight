#include<iostream>
using namespace std;

int main(){
    int  n, k;
    cin >> n >> k;
    int lmax = 1;
    int ans = 0;
    while(lmax <= n){
        ans++;
        lmax *= k;
    }
    cout << ans << endl;
    return 0;
}