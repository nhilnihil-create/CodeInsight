#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
        long long n,x,y;
        cin >> n >> x >> y;
        vector<int>ans(n,0);
        for(long long i = 1;i < n;i++){
            for(long long  j = i + 1;j <= n;j++){
                long long mn = min(j - i,abs(x - i) + abs(y - j) + 1);
                ans[mn]++;
            }
        }
        for(int i = 1; i < n;i++){
            cout << ans[i] << endl;
        }
}
