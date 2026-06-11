#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, k) for (int i = (s); i < (int)(k); i++)

int main(){
    int n,x,pay;
    cin >> n;
    int ans = 0;
    for(x = 0;x<=n;x++){
        pay = x + (x*8)/100;
        if(pay==n){
            cout << x << endl;
            return 0;
        }

        
    }
    cout << ":(" << endl;
    return 0;
}