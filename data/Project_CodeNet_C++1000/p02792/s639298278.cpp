#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
using lint = long int;

int N;
int dp[10][10] = { 0 };
lint res = 0;


void digit_array(int n){
    int x;
    for(int i = 0; i <= n; i++){
        x = i;
        while(x >= 10) x /= 10;
        ++dp[x][i%10];
    }
}


int main(){
    cin >> N;
    digit_array(N);

    for(int i = 1; i < 10; i++){
        for(int j = 1; j < 10; j++) res += dp[i][j] * dp[j][i];
    }

    cout << res << endl;
    return 0;

}
