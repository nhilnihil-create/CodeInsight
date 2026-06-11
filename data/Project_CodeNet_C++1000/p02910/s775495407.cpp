#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin >> s;
    bool check = true;

    rep(i, s.length()){
        if(!(i%2)){
            if(s[i] == 'L') check = false;
        }
        else{
            if(s[i] == 'R') check = false;
        }
    }

    if(check) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}