#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main()
{
    int n; 
    string s;
    cin >> n >> s;

    rep(i,s.size()) {
        rep(j,n) {
            if(s[i] == 'Z') s[i] = 'A';
            else s[i]++;
        }
    }

    cout << s << endl;

    return 0;
}