#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> ans;
    for(int i = n-1; i >= 0; i--){
        int j = i+1;
        int k = 2;
        int cnt = 0;
        while(j * k <= n){
            cnt += b[j*k-1];
            k++;
        }
        if(cnt % 2 != a[i]){
            b[i] = 1;
            ans.push_back(j);
        }
    }
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << endl;
    return 0;
}