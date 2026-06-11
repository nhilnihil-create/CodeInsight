#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> h(n);
    for(int i=0; i<n; i++) cin >> h[i];
    bool ans = true;

    for(int i=0; i<n; i++){
        if(h[i-1]-h[i] >= 1 && i!=0){ // 前より小さかったらアウト
            ans = false; break;
        }else if(h[i+1]>h[i] && i!=n-1){ // 次が大きかったら小さくしておく
            h[i+1]--;
        }
    }
    if(ans) cout << "Yes" << endl;
    else    cout << "No" << endl;

    return 0;
}