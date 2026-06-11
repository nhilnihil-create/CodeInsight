#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

bool is_integer(double x) {
    return std::floor(x)==x;
}

int main(){
    int ans(0);
    char c[3];
    rep(i,3){
        cin >> c[i];
        if(c[i]=='R')
            ans++;
    }

    if(ans==2&&c[1]=='S'){
        cout << 1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}