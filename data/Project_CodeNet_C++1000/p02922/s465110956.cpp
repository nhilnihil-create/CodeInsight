#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int A, B = 0;
    cin >> A >> B;
    int ans = 0;
    int tap = 1;

    while(tap<B){
        tap += A - 1;
        ans++;
    }
    
    cout << ans << endl;

    return 0;
}