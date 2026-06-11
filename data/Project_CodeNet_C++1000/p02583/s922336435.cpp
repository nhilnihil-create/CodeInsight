#include<bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    int data[n];

    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    
    int ans = 0;
    for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n-1; j++) {
            for (int k = j+1; k < n; k++) {
                if (data[i]==data[j] || data[j]==data[k] || data[k]==data[i]) {
                    continue;
                }
                if (abs(data[i]-data[j]) < data[k] && data[k] < data[i]+data[j]) {
                    ans ++;
                }
            }
        }
    }
    cout << ans << endl;
}