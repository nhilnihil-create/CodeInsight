#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k; cin >> n >> k;
    int r,s,p; cin >> r >> s >> p;
    string t; cin >> t;
    //自分の出す手に変換
    for(int i=0; i<n; i++){
        if(t[i] == 'r') t[i] = 'p';
        else if(t[i] == 's') t[i] = 'r';
        else /*(t[i] == 'p')*/ t[i] = 's';
    }
    for(int i=0; i<n; i++){
        if(i+k<n){
            if(t[i] == t[i+k]) t[i+k] = 'x';
        }
    }
    long ans = 0;
    for(int i=0; i<n; i++){
        if(t[i] == 'r') ans += r;
        if(t[i] == 's') ans += s;
        if(t[i] == 'p') ans += p;        
    }
    //cout << t << endl;
    cout << ans << endl;
}
