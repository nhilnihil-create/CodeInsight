#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265359

int main() {
    string s;
    cin >> s;
    bool f = false;
    int ans = 0, count = 0;
    for(char c : s){
        if(c == 'R'){
            if(f) count++;
            else count = 1;
            f = true;
        }else{
            f = false;
            count = 0;
        }
        ans = max(ans, count);
    }
    cout << ans << endl;
    return 0;
}