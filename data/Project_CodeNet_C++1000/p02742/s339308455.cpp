#include <bits/stdc++.h>
using namespace std;
int main(){
    long long h,w;
    cin >> h >> w;
    long long oddColomn = h/2 + h%2;
    long long evenColomn = h/2;
    long long ans = oddColomn*(w/2+w%2) +evenColomn*(w/2);
    // cout << oddColomn << endl;
    // cout << evenColomn << endl;
    if(w==1){
        cout << 1 << endl;;
    }else if(h==1){
        cout << 1 << endl;
    }else{
        cout << ans << endl;
    }

}