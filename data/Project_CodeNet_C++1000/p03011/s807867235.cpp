#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int P,Q,R;
    cin >> P >> Q >> R;
    int ans = P + Q + R - max(P,max(Q,R));
    
    cout << ans;
    
}
