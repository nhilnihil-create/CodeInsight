#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    bool flag = true;
    if(n%2) flag = false;

    for(int i=0; i<n/2; i++){
        if(s[i] != s[i+n/2]) flag = false;
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}