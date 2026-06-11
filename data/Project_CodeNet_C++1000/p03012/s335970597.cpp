#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    // int w[100];
    cin >> n;
    vector<int>w(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin >> w[i];
        sum += w[i];
    }
    int ans=1e9;
    int now=0;
    for(int i=0;i<n;i++){
        now += w[i];
        ans=min(ans,abs(sum-now-now));
        // if(abs(sum-2*now)<=ans){
        //     ans = abs(sum-2*now);
        // }
    }
    cout << ans;
    return 0;
}
//今回の学び 
// １．絶対値にする関数abc()は引数が１つのみ。
// 
// 
// 
// 
// 
//