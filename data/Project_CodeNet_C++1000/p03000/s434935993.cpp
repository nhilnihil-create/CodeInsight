#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> D(n + 1);
    D[0] = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        D[i + 1] = D[i] + x;
    }
    int ans = 0;
    for(int i = 0; i <= n; i++){
        if(D[i] <= x){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}