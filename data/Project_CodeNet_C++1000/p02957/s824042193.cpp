#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    int ans = -1;
    rep(i,max(a,b)){
        if(abs(a-i)==abs(b-i)){
            ans=i;
        }
    }
    if(ans != -1){
        cout << ans << endl;
    }
    else{

        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}