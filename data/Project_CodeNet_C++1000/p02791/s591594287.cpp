#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    int p[n];
    int c = 1;
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    int m = p[0];
    for(int i = 1; i < n; i++){
        if(p[i]<m){
            c++;
            m = p[i];
        }
    }
    cout << c << endl;

    return 0;
}