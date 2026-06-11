#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int l = 0, r = n-1;
    int cnt = 0;
    while(l<r){
        while(l<n-1 && s[l]!='W') l++;
        while(r>0 && s[r]!='R') r--;
        if(l>=r) break;
        s[l] = 'R'; s[r] = 'W';
        cnt++;
    }
    //cout << s << endl;
    cout << cnt << endl;
    return 0;
}