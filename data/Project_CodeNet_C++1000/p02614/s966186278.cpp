#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int h, w, k;
    cin >> h >> w >> k;

    string s[h];
    rep(i, h) cin >> s[i];

    int ans = 0;

    for(int i=0; i < (1<<h+w); i++)
    {
        int cnt = 0;
        bitset<12> b(i);

        for(int j=0; j < h; j++)
        {
            if(b.test(j)) continue;
            
            for(int k=h; k < w+h; k++)
            {
                if(b.test(k)) continue;
                if(s[j].at(k-h) == '#') cnt++;
            }

        }

        if(cnt == k) ans++;
    }

    cout << ans << endl;
}