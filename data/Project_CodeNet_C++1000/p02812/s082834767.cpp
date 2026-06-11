#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    int i = 0;
    while(i+2 < n) {
        if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') {
            cnt++;
            i += 3;
        } else {
            i++;
        }
    }    
    cout << cnt << "\n";
}