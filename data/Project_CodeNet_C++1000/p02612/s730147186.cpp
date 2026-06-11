#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = n % 1000;
    ans = 1000 - ans;
    if(ans == 1000){
        ans = 0;
    }
    cout << ans << endl;
    return 0;
}