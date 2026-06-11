#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int func(int num){
    int ans = 1;
    while(num / 10 != 0){
        ans++;
        num /= 10;
    }
    return ans;
}

int main(){
    int N;
    cin >> N;
    int ans = 0;
    for(int i = N; i > 0; i--){
        int len = func(i);
        if(len % 2 == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}