#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    int cnt = 0;
    int max = -1;
    ll bh;
    for(int i=0;i<n;i++){
        ll h;
        cin >> h;
        if(i == 0){
            bh = h - 1;
        }
        if( h <= bh ){
            cnt++;
        }else{
            cnt = 0;
        }
        if(max < cnt) max = cnt;
        bh = h;
    }
    cout << max << endl;
}