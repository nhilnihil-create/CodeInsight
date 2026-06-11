#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;


int main(){
    int n,m;
    cin >> n >> m;
    int h[n + 1];
    int ma[n + 1];
    for(int i = 1; i <= n;i++){
        cin >> h[i];
        ma[i]=0;
    }
    for(int i = 0;i < m;i++){
        int a;
        int b;
        cin >> a >> b;
        ma[a] = max(ma[a],h[b]);
        ma[b] = max(ma[b],h[a]);
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        if(h[i] > ma[i])
            ans++;
    }
    cout << ans << endl;
}


