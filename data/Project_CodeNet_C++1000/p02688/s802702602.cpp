#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> N(n);
    for(int i=0; i<k; i++){
        int m;
        cin >> m;
        for(int j=0; j<m; j++){
            int a;
            cin >> a;
            N[a-1] = 1;
        }
    }

    int ans=0;
    for(int i=0; i<n; i++){
        if(N[i] == 0) ans++;
    }

    cout << ans << endl;

    return 0;
}