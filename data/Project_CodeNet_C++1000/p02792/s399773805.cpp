#include <string>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> table(10, vector<int>(10, 0));

    for(int i = 1; i <= n; i++){
        if(i % 10 == 0) continue;
        int end = i % 10;
        int tmp = i;
        while(tmp / 10 != 0) tmp /= 10;
        int front = tmp;
        table[front][end]++;
    }

    int ans = 0;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= i; j++){
            if(i == j) ans += table[i][j] * table[i][j];
            else ans += table[i][j] * table[j][i] * 2; 
        }
    }
    cout << ans << endl;
}