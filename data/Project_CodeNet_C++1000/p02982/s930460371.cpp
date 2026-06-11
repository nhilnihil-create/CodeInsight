#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, d; cin >> n >> d;
    int a[n][d];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < d; j++)
            cin >> a[i][j];

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int res = 0;
            for(int k = 0; k < d; k++) res += (a[i][k] - a[j][k]) * (a[i][k] - a[j][k]);
            if(ceil(sqrt(res)) == floor(sqrt(res))) cnt++; 
        }
    }
    cout << cnt;
}