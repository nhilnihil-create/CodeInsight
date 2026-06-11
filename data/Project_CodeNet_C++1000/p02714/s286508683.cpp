#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)



int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    long int cnt_r, cnt_g, cnt_b;
    cnt_r = cnt_g = cnt_b = 0;
    rep(i,n) {
        if(s[i] == 'R')
            cnt_r++;
        else if(s[i] == 'G')
            cnt_g++;
        else if(s[i] == 'B')
            cnt_b++;
    }
    
    long int cnt = cnt_r * cnt_g * cnt_b;
    //cout << cnt << endl;
    
    rep(j,n) rep(i,j) {
        int k = j + (j-i);
        if(k < n && s[i] != s[j] && s[j] != s[k] && s[k] != s[i])
            cnt--;
    }
    
    if(cnt < 0)
        cnt = 0;
    
    cout << cnt << endl;
    
    return 0;
}


