#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> dp(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        dp[a[i]-1]=i+1;
    }
    for(int i = 0; i < n; i++){
        cout << dp[i] << " ";
    }
    cout << endl;
    return 0;
}