#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    
    h[0]--;
    for (int i = 0; i + 1 < n; i++){
        if (h[i] + 1 <= h[i+1]) h[i+1]--;
        else if (h[i] == h[i+1]) continue;
        else{
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
}
