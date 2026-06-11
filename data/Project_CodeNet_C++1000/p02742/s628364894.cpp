#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//二項係数の計算
int nCr(int A, int B) {
    ll ans = 1;
    for (int i = 0; i < B; i++) {
        ans*= A - i;
    }
    for (int i = 0; i < B; i++) {
        ans /= i + 1;
    }
    return ans;
}
int main() {
    ll H,W;
    cin>>H>>W;
    if(H==1||W==1){
        cout<<1<<endl;
    }
    else{
        if(H%2==0){
            cout<<H*W/2<<endl;
        }
        else{
            if(W%2==0){
                cout<<H*W/2<<endl;
            }
            else
            {
                cout<<H*W/2+1<<endl;
            }
            
        }

    }
}
