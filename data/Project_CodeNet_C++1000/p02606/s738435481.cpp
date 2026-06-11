#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int l, r, d;
    cin >> l >> r >> d;
    
    int res = 0;
    for(;l <= r; l++){
        if(l%d == 0){
            //cout << l << " ";
            res += 1;
        }
    }
    
    cout << res << endl;
    
}
