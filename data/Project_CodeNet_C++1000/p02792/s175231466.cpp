#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

int get_top_digit(int x){
    int res;
    while(x > 0){
        res = x % 10;
        x /= 10;
    }
    return res;
}

int get_last_digit(int x){
    return x % 10;
}

int main(void){
    int n;
    cin >> n;
    int cnt[10][10];
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cnt[i][j] = 0;
        }
    }

    for(int i=1; i<=n; i++){
        int top = get_top_digit(i);
        int last = get_last_digit(i);
        cnt[top][last]++;
    }

    int ans = 0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            ans += cnt[i][j]*cnt[j][i];
        }
    }

    cout << ans << endl;
    return 0;
}