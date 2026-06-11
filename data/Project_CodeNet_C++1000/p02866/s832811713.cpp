#include<bits/stdc++.h>
using namespace std;
#define MOD2 998244353

int main(){
    int n;
    cin >> n;
    vector<long long> d(n),dist(n);
    long long ans = 1;
    for(int i = 0;i < n;i++){
        cin >> d[i];
        dist[d[i]]++;
    }
    if(d[0] != 0 || dist[0] != 1){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1;i < n;i++){
        for(int j = 1;j <= dist[i];j++){
            ans = ans * dist[i - 1] % MOD2;
        }
    }
    cout << ans << endl;
}
