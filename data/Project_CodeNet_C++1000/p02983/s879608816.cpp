#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int l,r;
    cin >> l >> r;
    int ans=2018;
    
    if(l/2019 != r/2019) cout << 0 << endl;
    else{
        l%=2019;
        r%=2019;
        for(int i=l; i<r; i++){
            for(int j=l+1; j<=r; j++){
                if(i!=j) ans=min(ans,(i*j)%2019);
            }
        }
        cout << ans << endl;
    }
}