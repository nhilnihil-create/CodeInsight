#include <bits/stdc++.h>
#define Phuong_ ios_base::sync_with_stdio(0); cin.tie(0);
#define REP(i,a,b) for(int i=a; i<=b; ++i)

/// easy access -------------
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
typedef pair<int,int> pi;
typedef tuple<bool, int, int> tp;
typedef vector<vector<int>> vv;
///-------------------------


int main()
{
    Phuong_; /// <3333
    string s;
    cin >> s;
    if (s=="RRR") cout << 3; else
    if (s[0] == s[1] && s[0] == 'R') cout << 2; else
    if (s[1]==s[2] && s[1] =='R') cout << 2; else
    {
        for(int i=0; i<3; ++i) if (s[i]=='R'){
            cout << 1;
            return 0;
        }
        cout << 0;
    }
    return 0;
}
