#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<char> s(n);
    for(int i =0; i<n; i++) cin >> s[i];

    bool ans = true;
    if(n % 2 == 0) {
        for(int i = 0; i<n; i++){
                if( s[i] != s[n/2 + i])  ans = false;
                if( i == n/2 - 1) break;
        }
    }
    else {
        ans = false;
    }

    if(ans) puts("Yes");
    else puts("No");

}