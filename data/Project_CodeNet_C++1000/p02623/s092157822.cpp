#include<iostream>
#include<stdio.h>
#include<string.h>
#include <algorithm>
using namespace std;

int main(void){
    int n,m,k, ans = 0, x = 0;
    cin >> n >> m >> k;
    int a[n],b[m];
    unsigned long sum = 0, bsum = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++){
        cin >> b[i];
        bsum += b[i];
    } 

    int y = m;
    while(k >= sum){
        while(y >= 0){
            if(bsum + sum > k){
                y--;
                bsum = bsum - b[y];
            }else break;
        }
        ans = max({ans,x + y});
        if(x == n) break;
        sum += a[x];
        x++;
    }

    cout << ans << endl;

    return 0;
}