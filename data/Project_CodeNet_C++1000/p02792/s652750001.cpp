#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int num[12][12];

int main(){
    int n;
    cin >> n;
    memset(num, 0, sizeof(num));
    for(int k = 1; k <= n; k++){
        int last = k % 10;
        int top = k;
        while(top >= 10){
            top /= 10;
        }
        num[top][last]++;
    }
    long long int ans = 0;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++)ans += (long long int)num[i][j] * num[j][i];
    }
    cout << ans << endl;
    return 0;
}