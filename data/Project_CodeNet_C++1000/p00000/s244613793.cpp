#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1; i<=n; i++)
int main(){
    rep(i,9){
        rep(j,9){
            cout << i << 'x' << j << '=' << i*j << endl;
        }
    }
    return 0;
}
