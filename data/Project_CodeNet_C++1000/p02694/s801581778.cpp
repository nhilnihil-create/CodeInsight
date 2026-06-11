#include <bits/stdc++.h>
using namespace std;
int main(void){
    int64_t X,A,ans;
    cin >> X;
    A=100;
    ans=0;
    while(A<X) {
        A+=A/100;
        ans++;
    }
    
    cout << ans << endl;
}
