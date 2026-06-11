#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll H,W;
    cin >> H >> W;
    if (H == 1 || W == 1) cout << 1 << endl;
    else{
        if ((H * W) % 2 == 0) cout << (H * W) / 2 << endl;
        else cout << (H * W + 1) / 2 << endl;
    }
}