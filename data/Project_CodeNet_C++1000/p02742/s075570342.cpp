#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long 

int main(void){
    ull w, h;
    cin >> h >> w;
    ull ans = h*w;

    if(h==1 || w == 1){
        cout << 1;
        return 0;
    }

    if(ans&1)
        cout << (ans+1)/2;
    else
        cout << ans/2;

    return 0;
}
