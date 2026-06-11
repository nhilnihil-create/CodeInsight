#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int a[10100];
    int total = 0;
    for(int i = 0; i < m; i++){
        cin >> a[i];
        total += a[i];
    }
    if(total > n) cout << -1 << endl;
    else cout << n-total << endl;
} 