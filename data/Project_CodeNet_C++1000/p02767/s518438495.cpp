#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    int ans = 1e9;
    for(int p = 1; p <= 100; p++){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += (x[i]-p)*(x[i]-p);
        }
        if(ans > sum) ans = sum;
    }
    cout << ans << endl;
    return 0;
}