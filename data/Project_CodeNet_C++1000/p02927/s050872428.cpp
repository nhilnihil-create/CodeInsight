#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isSeki(int m, int d){
    int d10 = d / 10;
    int d1 = d % 10;
    
    if (d1 < 2) return false;
    if (d10 < 2) return false;
    
    if (d1 * d10 == m) return true;
    else return false;
}

int main(void){
    int m, d;
    cin >> m >> d;
    
    int ans = 0;
    
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= d; j++){
            if (isSeki(i,j)) ans++;
        }
    }
    cout << ans << endl;
}
