#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, streak = 0;
    bool ok = false;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(a==b){
            streak++;
        } else {
            streak = 0;
        }
        if(streak == 3) ok = true;
    }
    cout << (ok?"Yes":"No");
}