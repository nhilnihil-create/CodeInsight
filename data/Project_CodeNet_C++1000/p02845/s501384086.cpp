#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), d(n+5);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    const int MOD= 1e9+7;
    long long ans = 1;
    d[0] = 3;
    for(int i = 0; i < n; i++){
        ans = (ans * d[a[i]])%MOD;
        d[a[i]]--;
        d[a[i]+1]++;
    }
    cout << ans;
}
