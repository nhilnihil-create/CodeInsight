#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int ok = 0;
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
        int ok = 1;
        if(i >= 2){
            for(int j=i-2; j<=i; j++){
                ok &= (a[j] == b[j]);
            }
            if(ok){
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}