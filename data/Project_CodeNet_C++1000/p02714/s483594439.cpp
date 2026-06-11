#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n,r=0,g=0,b=0;
    string s;
    ll cnt1=0;
    cin >> n >> s;
    for (int i=0;i<n;i++) {
        if (s[i]=='R') r++;
        else if (s[i]=='G') g++;
        else if (s[i]=='B') b++;
    }
    cnt1=r*g*b;

    for (int i=0;i<n;i++) {
        for (int j=1;j<n;j++) {
            if (i+2*j>=n) {continue;}
            if (s[i]!=s[i+j] && s[i]!=s[i+j*2] && s[i+j]!=s[i+j*2])
                cnt1--;
        }
    }
    cout << cnt1;
}

