#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000

int main(){

    while(1){
    int n; cin >> n;
    if(!n) break;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(i > 0) a[i] += a[i - 1];
    }
    a[0] = 0;
    int ans = a[1];
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            ans = max(ans, a[j] - a[i]);
        }
    }

    cout << ans << endl;
    }
    return 0;
}