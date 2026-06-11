#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    string s;
    cin >> s;
    char p = '.';
    ll r = 0;
    ll i;
    for(i=0; i<s.size(); i++) {
        if(s[i] == p)
            p = '.', i++;
        else
            p = s[i];
        r++;
    }
    if(i == s.size()+1) r--;
    cout << r << endl;
}
