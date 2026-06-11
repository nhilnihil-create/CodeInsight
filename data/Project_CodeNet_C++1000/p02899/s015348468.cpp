#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1000000007;
const ll INF = 1001001001;

int main(){
    int n; cin >> n;
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        ans[a - 1] = i + 1;
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
}
