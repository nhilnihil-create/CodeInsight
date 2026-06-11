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
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> data(n+1, vector<int>(m+2));
    for(int i = 0; i < n; i++){
        cin >> data[i][0];
        for(int j = 1; j <= m; j++) cin >> data[i][j];
    }
    int minPrice = 1000000000;
    for(int i = 0; i < pow(2, n); i++){
        vector<int> binary(n);
        int tmp = i, k = 0;
        while(tmp != 0){
            binary[k] = tmp % 2;
            tmp /= 2;
            k++; 
        }
        vector<int> calc(n+1);
        rep(j,n){
            if(binary[j] == 1){
                for(int k = 0; k <= m; k++) calc[k] += data[j][k];
            }
        }
        for(int k = 1; k <= m; k++){
            if(calc[k] < x) break;
            if(k == m) minPrice = min(minPrice, calc[0]);
        } 
        cout << endl;
    }
    if(minPrice == 1000000000) cout << "-1" << endl;
    else cout << minPrice << endl;
}