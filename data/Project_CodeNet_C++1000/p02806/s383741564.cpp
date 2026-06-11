#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s[n];
    int t[n];
    long long sum = 0;
    for(int i = 0 ; i < n; i++){
        cin >> s[i] >> t[i];
        sum += t[i];
    }
    string x;
    cin >> x;
    bool p = true;;
    for(int i = 0; i < n; i++){
        if(p){
            sum -= t[i];
        }
        if(x == s[i]){
            p = false;
        }
    }
    cout << sum << endl;
    return 0;
}