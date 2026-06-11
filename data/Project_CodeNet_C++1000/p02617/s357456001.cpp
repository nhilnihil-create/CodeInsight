//
//  main.cpp
//  F
//
//  Created by 曾憲揚 on 2020/8/9.
//  Copyright © 2020 曾憲揚. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;
int u[maxn], v[maxn];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    for(int i=1; i<=n-1; i++){
        cin >> u[i] >> v[i];
    }
    
    long long ans = 0;
    
    for(int i=1; i<=n; i++){
        ans += (1LL * i * (n-i+1));
    }
    
    for(int i=1; i<=n-1; i++){
        int m = min(u[i], v[i]), M = max(u[i], v[i]);
        ans -= (1LL * m * (n-M+1));
    }
    
    cout << ans << endl;
    
    return 0;
}
