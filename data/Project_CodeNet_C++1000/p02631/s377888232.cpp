#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1000000007;
const ll INF = 1001001001;

int main(){
    int n; cin >> n;
    int tmp = 0;
    vector<int> a(n), ans(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        tmp ^= a[i];
    }
    for(int i = 0; i < n; i++){
        ans[i] = tmp ^ a[i];
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
}
