#include<bits/stdc++.h>
 
using namespace std;
 
 
int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int &x : x) cin >> x;
    int ans = 1000000;
    for (int i = 1; i <= 200; i++){
        int temp = 0;
        for (int j = 0; j < n; j++){
            temp += (x[j] - i) * (x[j] - i);
        }
        if (temp < ans) ans = temp;
    }
    cout << ans << endl;
    return 0;
}