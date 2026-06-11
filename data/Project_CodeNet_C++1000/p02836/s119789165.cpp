#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int ans = 0;
    string s;
    cin >> s;
    int i = 0, j = s.size() - 1;
    while(i <= j){
        if(s[i] != s[j]){
            ans++;
        }
        i++; j--;
    }
    cout << ans << endl;
    return 0;
}