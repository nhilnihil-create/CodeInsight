#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;

int main(){
    int n;
    string s,t;
    cin >> n >> s;

    bool flag = true;
    if(n%2 == 1) flag = false;
    else{
        rep(i, n / 2) if (s[i] != s[n / 2 + i]) flag = false;
    }
    if(flag)
        cout << "Yes" << endl;
        else
            cout << "No" << endl;

        return 0;
}