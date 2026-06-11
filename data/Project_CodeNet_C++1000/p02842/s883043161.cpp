#include <iostream>
using namespace std;

int main() {
    int n;
    int ans = -1;
    cin >> n;
    for(int i = 0; i  <= n; i ++){
        int tmp = i*1.08;
        if(tmp == n){
            ans = i;
            break;
        }
    }
    if(ans == -1) cout << ":(";
    else cout << ans;


    return 0;
}