#include <bits/stdc++.h>
using namespace std;

bool hantei(int n){
    bool hantei;
    int cnt = 0;
    while(n>0){
        n/=10;
        cnt++;
    }
    if(cnt%2==0){
        hantei = false;
    }else{
        hantei = true;
    }
    return hantei;
}

int main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(hantei(i)) ans++;
    }
    cout << ans << endl;
}