#include <bits/stdc++.h>

using namespace std;

#define bug(x) cerr << #x << " = " << x << '\n'
#define ll     long long
#define maxn

int main() {
        //freopen(".inp","r",stdin);

        int n;
        cin >> n;
        string s;
        cin >> s;

        int r = 0;
        for(int i = 0; s[i]; ++ i)
            if(s[i] == 'R') r ++;
        int cnt = 0;
        for(int i = 0; i < r; ++ i)
            if(s[i] == 'W') cnt ++;
        cout << cnt;
}

